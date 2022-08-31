//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[200001];
llo tree[4*200001];
llo pre[200001];
llo pre2[200001];
llo pre3[200001];
llo ind[200001];
 
const llo mod=1e9+7;
void update(llo no,llo l,llo r,llo i,llo j){
	if(l==r){
		tree[no]=(tree[no]+j);
		if(tree[no]>=mod){
			tree[no]-=mod;//%mod;
		}
	}
	else{
		llo mid=(l+r)/2;
		if(i<=mid){
			update(no*2+1,l,mid,i,j);
		}
		else{
			update(no*2+2,mid+1,r,i,j);
		}
		tree[no]=tree[no*2+1]+tree[no*2+2];
		if(tree[no]>=mod){
			tree[no]-=mod;
		}
	}
}
llo query(llo no,llo l,llo r,llo aa,llo bb){
	if(r<aa or l>bb or aa>bb){
		return 0;
	}
	if(aa<=l and r<=bb){
		return tree[no];
	}
	llo mid=(l+r)/2;
	return query(no*2+1,l,mid,aa,bb)+query(no*2+2,mid+1,r,aa,bb);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		map<llo,llo> ss;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			ss[it[i]]++;
		}
		llo ind3=0;
		map<llo,llo> tt;
		for(auto j:ss){
			tt[j.a]=ind3;
			ind3++;
		}
		vector<pair<llo,llo>> kk;
		for(llo i=0;i<n;i++){
			it[i]=tt[it[i]];
			kk.pb({it[i],-i});
		}
		sort(kk.begin(),kk.end());
		reverse(kk.begin(),kk.end());
		set<llo> zz;
		llo ma=-1;
		for(auto j:kk){
 
			
			ind[-j.b]=-1;
			//if(ma>=0){
				if(ma>-j.b){
					ind[-j.b]=ma;
				}
			//}
			ma=max(ma,-j.b);
			//zz.insert(j.b);
			
		}
		for(llo i=0;i<4*n;i++){
			tree[i]=0;
		}
		for(llo i=0;i<n;i++){
			pre[i]=(query(0,0,n-1,0,it[i]-1)+1)%mod;
			update(0,0,n-1,it[i],pre[i]);
		}
		for(llo i=0;i<4*n;i++){
			tree[i]=0;
		}
		for(llo i=n-1;i>=0;i--){
			pre2[i]=(query(0,0,n-1,it[i]+1,n-1)+1)%mod;
			update(0,0,n-1,it[i],pre2[i]);
		}
		for(llo i=0;i<4*n;i++){
			tree[i]=0;
		}
		for(llo i=n-1;i>=0;i--){
			pre3[i]=0;
			if(ind[i]!=-1){
				pre3[i]=(query(0,0,n-1,it[i]+1,it[ind[i]]-1)+1)%mod;
				update(0,0,n-1,it[i],pre3[i]);
			}
		}
		llo ans=0;
		for(llo i=0;i<n;i++){
			if(ind[i]!=-1){
			//cout<<i<<":"<<ind[i]<<endl;
			//	cout<<pre[i]<<":"<<pre2[i]<<":"<<pre3[i]<<endl;
 
				llo zz=(pre2[i]-pre3[i]+mod);//%mod;
				if(zz>=mod){
					zz-=mod;
				}
				ans=(ans+((zz*pre[i])%mod))%mod;
			}
		}
		cout<<ans<<endl;
 
	}	
 
 
 
 
 
 
 
	return 0;
}