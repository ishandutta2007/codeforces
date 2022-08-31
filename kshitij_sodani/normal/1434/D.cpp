//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int n,m;
vector<pair<int,int>> adj[500001];
pair<int,int> ma={-1,-1};
void dfs(llo no,llo par=-1,llo lev=0){
	if(lev>ma.a){
		ma={lev,no};
	}
	for(auto j:adj[no]){
		if(j.a!=par){
			dfs(j.a,no,lev+1);
		}
	}
}
int st[2][500001];
int endd[2][500001];
pair<int,int> val[2][500001];
//int dd[2][500001];
int cur=0;
int co=0;
void dfs2(int no,int par2=-1,int levv=0,int val2=0){
	st[cur][no]=co;
	val[cur][co]={val2,levv};
	co++;
	
	for(auto j:adj[no]){
		if(j.a!=par2){
			dfs2(j.a,no,levv+1,val2^j.b);
		}
	}
	endd[cur][no]=co-1;
}
int tree[2][500001*4][2];
int lazy[2][500001*4];
void build(int no,int l,int r){
	if(l==r){
		tree[cur][no][val[cur][l].a]=val[cur][l].b;
	//	cout<<l<<"::"<<val[cur][l].a<<",,"<<val[cur][l].b<<endl;
	}
	else{
		int mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
		tree[cur][no][0]=max(tree[cur][no*2+1][0],tree[cur][no*2+2][0]);
		tree[cur][no][1]=max(tree[cur][no*2+1][1],tree[cur][no*2+2][1]);
	}
}
void update(int no,int l,int r,int aa,int bb){
	if(lazy[cur][no]){
		lazy[cur][no]=0;
		if(l<r){
			lazy[cur][no*2+1]^=1;
			lazy[cur][no*2+2]^=1;
		}
		swap(tree[cur][no][0],tree[cur][no][1]);
	}
	if(aa>r or bb<l){
		return;
	}
	if(aa<=l and r<=bb){
		swap(tree[cur][no][0],tree[cur][no][1]);
		if(l<r){
			lazy[cur][no*2+1]^=1;
			lazy[cur][no*2+2]^=1;
		}
	}
	else{
		int mid=(l+r)/2;
		update(no*2+1,l,mid,aa,bb);
		update(no*2+2,mid+1,r,aa,bb);
		tree[cur][no][0]=max(tree[cur][no*2+1][0],tree[cur][no*2+2][0]);
		tree[cur][no][1]=max(tree[cur][no*2+1][1],tree[cur][no*2+2][1]);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<pair<int,int>> ed;
	for(int i=0;i<n-1;i++){
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		aa--;
		bb--;
		adj[aa].pb({bb,cc});
		adj[bb].pb({aa,cc});
		ed.pb({aa,bb});
	}
	dfs(0);
	int x=ma.b;
	ma={-1,-1};
	dfs(x);
//	cout<<ma.a<<":"<<ma.b<<endl;
	int y=ma.b;
	cur=0;
	dfs2(x);
	build(0,0,n-1);
	co=0;
	cur=1;
	dfs2(y);
	//cout<<x<<":"<<y<<endl;
	build(0,0,n-1);
	cin>>m;
	while(m--){
		int ind;
		cin>>ind;
		ind--;
		pair<int,int> cc={ed[ind].a,ed[ind].b};

		if(st[0][cc.a]>st[0][cc.b]){
			swap(cc.a,cc.b);
		}
	//	cout<<cc.a<<":"<<cc.b<<endl;
	//	cout<<st[0][cc.b]<<",,"<<endd[0][cc.b]<<endl;
		cur=0;
		update(0,0,n-1,st[0][cc.b],endd[0][cc.b]);
		if(st[1][cc.a]>st[1][cc.b]){
			swap(cc.a,cc.b);
		}
		cur=1;
	//	cout<<cc.a<<":"<<cc.b<<endl;
	//	cout<<st[1][cc.b]<<",,"<<endd[1][cc.b]<<endl;
		update(0,0,n-1,st[1][cc.b],endd[1][cc.b]);
		cout<<max(tree[0][0][0],tree[1][0][0])<<endl;


	}











 
 
	return 0;
}