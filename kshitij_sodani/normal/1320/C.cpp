#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
#define mp make_pair
#define pb push_back
typedef int64_t llo;
#define a first
#define  b second
#define endl "\n"
vector<pair<llo,llo>> aa;
vector<pair<llo,llo>> bb;
vector<pair<llo,llo>> cc;
vector<pair<llo,llo>> dd;
llo tree[810000];
llo lazy[810000];
llo build(llo no,llo l,llo r){
	if(l==r){
		tree[no]=-dd[l].b;
	}
	else{
		llo mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
		tree[no]=max(tree[no*2+1],tree[no*2+2]);
	}
}
void update(llo no,llo l,llo r,llo aa,llo bb,llo add){
	if(lazy[no]!=0){
		tree[no]+=lazy[no];
		if(r>l){
			lazy[no*2+1]+=lazy[no];
			lazy[no*2+2]+=lazy[no];
		}
		lazy[no]=0;
	}
	////cout<<l<<" "<<r<<","<<aa<<" "<<bb<<" "<<add<<endl;
	if(aa>r or bb<l or l>r){
		return;
	}
	if(aa<=l and bb>=r){
		tree[no]+=add;
	//	//cout<<no<<endl;
		if(r>l){
			lazy[no*2+1]+=add;
			lazy[no*2+2]+=add;
		}
		return;
	}
	llo mid=(l+r)/2;
	update(no*2+1,l,mid,aa,bb,add);
	update(no*2+2,mid+1,r,aa,bb,add);
	tree[no]=max(tree[no*2+1],tree[no*2+2]);
}
llo query(llo no,llo l,llo r,llo aa,llo bb){
	if(lazy[no]!=0){
		tree[no]+=lazy[no];
		if(r>l){
			tree[no*2+1]+=lazy[no];
			tree[no*2+2]+=lazy[no];
		}
 
	}
	if(l>bb or r<aa or l>r){
		return -cc[0].b-dd[0].b;
	}
	if(l>=aa and r<=bb){
		return tree[no];
	}
	llo mid=(l+r)/2;
	llo ac=query(no*2+1,l,mid,aa,bb);
	llo cc=query(no*2+2,mid+1,r,aa,bb);
	
	return max(ac,cc);
		
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,m,p;
	cin>>n>>m>>p;
	memset(lazy,0,sizeof(lazy));
	llo d,ac,co;
	for(llo i=0;i<n;i++){
		cin>>ac>>co;
		aa.pb(mp(ac,co));
	}
	for(llo i=0;i<m;i++){
		cin>>d>>co;
		bb.pb(mp(d,co));
	}
	sort(aa.begin(),aa.end());
	sort(bb.begin(),bb.end());
	llo ma=aa[n-1].b;

	for(llo i=n-1;i>=0;i--){
		if(aa[i].b>ma){
			continue;
		}
		cc.pb(aa[i]);
		ma=min(ma,aa[i].b);
 
	}
	llo ans=-ma;
	ma=bb[m-1].b;
	for(llo i=m-1;i>=0;i--){
		if(bb[i].b>ma){
			continue;
		}
		dd.pb(bb[i]);
		ma=min(ma,bb[i].b);
	}
	ans-=ma;
	reverse(cc.begin(),cc.end());
	reverse(dd.begin(),dd.end());
	llo ooo=dd.size();
	build(0,0,ooo-1);

	vector<pair<pair<llo,llo>,llo>> mm;
	for(llo i=0;i<p;i++){
		cin>>ac>>d>>co;
		mm.pb(mp(mp(ac,d),co));
	}
	sort(mm.begin(),mm.end());
 
	llo ind=-1;
	vector<llo> pp;
	for(llo i=0;i<ooo;i++){
		pp.pb(dd[i].a);
		//cout<<dd[i].a<<":";
	}
 
	//cout<<query(0,0,ooo-1,0,ooo-1)<<","<<endl;
	for(llo i=0;i<cc.size();i++){
		while(ind<p-1){
			if(mm[ind+1].a.a<cc[i].a){
				ind+=1;
				llo co=upper_bound(pp.begin(),pp.end(),mm[ind].a.b)-pp.begin();
				if(co==pp.size()){
					continue;
				}
				while( pp[co]<=mm[ind].a.b){
					co+=1;
				}
				update(0,0,ooo-1,co,ooo-1,mm[ind].b);
				//cout<<co<<" "<<ind<<endl;
			}
			else{
				break;
			}
		}
		ans=max(ans,query(0,0,ooo-1,0,ooo-1)-cc[i].b);
	}
	cout<<ans<<endl;
 
 
 
 
 
 
 
 
 
 
 
	return 0;
}