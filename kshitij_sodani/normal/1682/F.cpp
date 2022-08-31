#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo aa[200001];
llo bb[200001];
llo pre[200001];
const llo mod=1e9+7;
llo n,q;
llo ans[200001];
vector<pair<llo,llo>> adj[200001];
llo tree[4*200001][2];
llo lazy[4*200001];
void build(llo no,llo l,llo r){
	if(l==r){
		if(bb[l]>0){
			llo xx=(aa[l]*bb[l])%mod;
			tree[no][0]=(mod-xx)%mod;//(aa[l]*(-bb[l]));
		//	cout<<l<<":"<<tree[no][0]<<endl;
		}	
		else{
			tree[no][0]=0;
		}
	}
	else{
		llo mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
		tree[no][0]=(tree[no*2+1][0]+tree[no*2+2][0]);
		if(tree[no][0]>=mod){
			tree[no][0]-=mod;
		}

	}
}
void push(llo no,llo l,llo r){
	tree[no][0]=(tree[no][0]+lazy[no]*tree[no][1])%mod;
	if(l<r){
		lazy[no*2+1]+=lazy[no];
		lazy[no*2+2]+=lazy[no];
		if(lazy[no*2+1]>=mod){
			lazy[no*2+1]-=mod;
		}
		if(lazy[no*2+2]>=mod){
			lazy[no*2+2]-=mod;
		}
	}
	lazy[no]=0;
}
void update(llo no,llo l,llo r,llo i,llo j){
	push(no,l,r);
	if(l==r){
		tree[no][1]=j;
		//cout<<i<<"::"<<tree[no][0]<<endl;
	}
	else{
		llo mid=(l+r)/2;
		if(i<=mid){
			update(no*2+1,l,mid,i,j);
			push(no*2+2,mid+1,r);
		}
		else{
			update(no*2+2,mid+1,r,i,j);
			push(no*2+1,l,mid);
		}
		tree[no][1]=(tree[no*2+1][1]+tree[no*2+2][1]);
		if(tree[no][1]>=mod){
			tree[no][1]-=mod;
		}
		tree[no][0]=(tree[no*2+1][0]+tree[no*2+2][0]);
		if(tree[no][0]>=mod){
			tree[no][0]-=mod;
		}
	}
}
llo query(llo no,llo l,llo r,llo aa,llo bb){
	push(no,l,r);
	if(r<aa or l>bb or aa>bb){
		return 0;
	}
	if(aa<=l and r<=bb){
		return tree[no][0];
	}
	llo mid=(l+r)/2;
	llo x=query(no*2+1,l,mid,aa,bb);
	llo y=query(no*2+2,mid+1,r,aa,bb);
	tree[no][1]=(tree[no*2+1][1]+tree[no*2+2][1]);
		if(tree[no][1]>=mod){
			tree[no][1]-=mod;
		}
		tree[no][0]=(tree[no*2+1][0]+tree[no*2+2][0]);
		if(tree[no][0]>=mod){
			tree[no][0]-=mod;
		}

	x+=y;
	if(x>=mod){
		x-=mod;
	}
	return x;
}
void solve(){
	for(llo i=0;i<4*n;i++){
		lazy[i]=0;
		tree[i][0]=0;
		tree[i][1]=0;
	}
	vector<pair<llo,pair<llo,llo>>> ss;
	for(llo i=0;i<n;i++){
		ss.pb({pre[i],{i,1}});//solve queries
		if(bb[i]>0){
			ss.pb({pre[i],{i,0}});//enable
			ss.pb({pre[i]+bb[i],{i,-1}});//disable
		}
	}
	sort(ss.begin(),ss.end());
	build(0,0,n-1);
	llo ok=0;
	llo pp=0;
	for(auto j:ss){
		if(ok==0){
			ok++;
		}
		else{
			lazy[0]=(lazy[0]+j.a-pp)%mod;
			lazy[0]=(lazy[0]+j.a-pp)%mod;
		}
	//	cout<<query(0,0,n-1,0,n-1)<<"<<"<<endl;
		if(j.b.b==1){
			//solve queries
			for(auto jj:adj[j.b.a]){
			//	cout<<j.a<<",,"<<endl;
				ans[jj.b]+=query(0,0,n-1,j.b.a,jj.a);
				ans[jj.b]%=mod;
			}
		}
		else if(j.b.b==0){
			//cout<<j.a<<"::"<<endl;
			update(0,0,n-1,j.b.a,aa[j.b.a]);
		}
		else if(j.b.b==-1){
			//cout<<j.a<<"::"<<endl;
			update(0,0,n-1,j.b.a,0);
		}


		pp=j.a;
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>q;
	for(llo i=0;i<n;i++){
		cin>>aa[i];
	}
	for(llo i=0;i<n;i++){
		cin>>bb[i];
		pre[i+1]=pre[i]+bb[i];
	}
	for(llo i=0;i<q;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb({bb,i});
	}
	solve();
	for(llo i=0;i<n;i++){
		bb[i]=-bb[i];
		pre[i+1]=pre[i]+bb[i];
	}
	solve();
	for(llo i=0;i<q;i++){
		cout<<ans[i]<<endl;
	}












	return 0;
}