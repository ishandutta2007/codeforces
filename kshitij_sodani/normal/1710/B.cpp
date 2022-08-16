#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo aa[600001];
llo bb[600001];
llo cc[600001];
vector<llo> pre[600001];
vector<llo> pre3[600001];
vector<llo> pre2[600001];
llo ans[600001];
llo tree[4*600001][3];
void build(llo no,llo l,llo r,llo ind){
	if(l==r){
		tree[no][ind+1]=ans[l]+ind*cc[l];
	}
	else{
		llo mid=(l+r)/2;
		build(no*2+1,l,mid,ind);
		build(no*2+2,mid+1,r,ind);
		tree[no][ind+1]=max(tree[no*2+1][ind+1],tree[no*2+2][ind+1]);
	}
}
llo query(llo no,llo l,llo r,llo aa,llo bb,llo ind){
	if(r<aa or l>bb or aa>bb){
		return -(llo)1e17;
	}
	if(aa<=l and r<=bb){
		return tree[no][ind+1];
	}
	llo mid=(l+r)/2;
	return max(query(no*2+1,l,mid,aa,bb,ind),query(no*2+2,mid+1,r,aa,bb,ind));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,m;
		cin>>n>>m;
		map<llo,llo> ss;
		for(llo i=0;i<n;i++){
			cin>>aa[i]>>bb[i];
			ss[aa[i]-bb[i]]++;
			ss[aa[i]+bb[i]]++;
			ss[aa[i]]++;
		}
		map<llo,llo> tt;
		llo ind=0;
		for(auto j:ss){
			tt[j.a]=ind;
			cc[ind]=j.a;
			ind++;
		}
		for(llo i=0;i<ind;i++){
			pre[i].clear();
			pre2[i].clear();
			pre3[i].clear();
		}
		for(llo i=0;i<n;i++){
			pre[tt[aa[i]-bb[i]]].pb(i);
			pre2[tt[aa[i]]].pb(i);
			pre3[tt[aa[i]+bb[i]]].pb(i);
		}
		llo cur=0;
		llo su=0;
		vector<llo> xx;
		for(llo i=0;i<ind;i++){
			if(i>0){
				cur+=su*(cc[i]-cc[i-1]);
			}
			//cur+=su;
			ans[i]=cur;
			//cout<<cc[i]<<":"<<cur<<endl;
			if(ans[i]>m){
				xx.pb(i);
			}
			for(auto j:pre[i]){
				su++;
			}
			for(auto j:pre2[i]){
				su-=2;
			}
			for(auto j:pre3[i]){
				su++;
			}
		}
		for(llo j=-1;j<=1;j++){
			build(0,0,ind-1,j);
		}
		for(llo i=0;i<n;i++){
			llo st=1;
			vector<llo> yy;
			yy.pb(tt[aa[i]-bb[i]]);
			yy.pb(tt[aa[i]]);
			yy.pb(tt[aa[i]+bb[i]]);
			if(xx.size()){
				if(xx[0]<yy[0]){
					st=0;
				}
				if(xx.back()>yy[2]){
					st=0;
				}
			}
			llo zz=query(0,0,ind-1,yy[0],yy[1],-1)+cc[yy[0]];
			if(zz>m){
				st=0;
			}
			//cout<<zz<<":";
			zz=query(0,0,ind-1,yy[1],yy[2],1)-cc[yy[2]];
			if(zz>m){
				st=0;
			}	
			//cout<<zz<<":";
			cout<<st;
			//cout<<endl;

		}
		cout<<endl;
	}





	return 0;
}