#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef  long long int llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
llo tree[800050];
llo lazy[800050];
llo fin[200002];
llo inf=200000000000001;

void build(llo no,llo l ,llo r){
	if(l==r){
		tree[no]=fin[l];
	}
	else{
		llo mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
		tree[no]=min(tree[no*2+1],tree[no*2+2]);
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
	//cout<<l<<" "<<r<<","<<aa<<" "<<bb<<" "<<add<<endl;
	if(aa>r or bb<l or l>r){
		return;
	}
	if(aa<=l and bb>=r){
		tree[no]+=add;
	//	cout<<no<<endl;
		if(r>l){
			lazy[no*2+1]+=add;
			lazy[no*2+2]+=add;
		}
		return;
	}
	llo mid=(l+r)/2;
	update(no*2+1,l,mid,aa,bb,add);
	update(no*2+2,mid+1,r,aa,bb,add);
	tree[no]=min(tree[no*2+1],tree[no*2+2]);
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
		return inf;
	}
	if(l>=aa and r<=bb){
		return tree[no];
	}
	llo mid=(l+r)/2;
	llo ac=query(no*2+1,l,mid,aa,bb);
	llo cc=query(no*2+2,mid+1,r,aa,bb);
	
	return min(ac,cc);
		
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	llo aa;
	cin>>n;
	vector<pair<llo,llo>> w;
	vector<llo> cd;
	for(llo i=0;i<n;i++){
		cin>>aa;
		w.pb(mp(aa,i));
		cd.pb(aa);
	}
	sort(w.begin(),w.end());
	vector<llo> cost; 
	llo co=0;
	for(llo j=0;j<n;j++){
		cin>>aa;
		cost.pb(aa);
		co+=aa;
	}
	co-=cost[n-1];
	fin[n]=co;
	llo ind2[n];
	for(llo i=0;i<n;i++){
		ind2[w[i].b]=i;
		//ind[i]=w[i].b;
	}
	for(llo i=1;i<n+1;i++){
		if(ind2[n-1]==i-1){
			co+=cost[n-1];
		}	
		else{
			co-=cost[w[i-1].b];
		}
		fin[n-i]=co;

	}
	llo ind[n];
	for(llo i=0;i<n;i++){
		//ind[w[i].b]=i;
		ind[w[i].b]=i;
	}
	/*for(llo i=0;i<n+1;i++){
		cout<<fin[i]<<" ";
	}
	cout<<endl;*/
	build(0,0,n);
	//cout<<inf<<endl;
	llo ma=query(0,0,n,0,n);
	//cout<<ma<<endl;
	for(llo i=n-2;i>0;i--){
	//	cout<<n-ind[i]<<" "<<n<<" "<<-cost[i]<<endl;
		update(0,0,n,n-ind[i],n,-cost[i]);
	//	cout<<0<<" "<<n-ind[i]-1<<" "<<cost[i]<<endl;
		update(0,0,n,0,n-ind[i]-1,cost[i]);
		

		ma=min(ma,query(0,0,n,0,n));
	}
	cout<<ma<<endl;






	return 0;
}