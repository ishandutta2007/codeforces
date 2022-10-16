/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int n;
int a[100005];
int hd[100005],nxt[100005];
vector<int>occ[100005];
#define SIZE 131072
int f[SIZE<<1];
void update(int x,int v){
	x+=SIZE;f[x]=max(f[x],v);
	while(x!=1){
		x>>=1;
		f[x]=max(f[x<<1],f[x<<1|1]);
	}
}
int query(int l,int r,int k,int ql,int qr){
	if(qr<l||r<ql)return -inf;
	if(ql<=l&&r<=qr)return f[k];
	return max(query(l,(l+r)/2,k<<1,ql,qr),query((l+r)/2+1,r,k<<1|1,ql,qr));
}
bool check(int x){
	for(int i=1;i<occ[x].size();i++){
		int l=occ[x][i-1],r=occ[x][i];
//		if(x==3)cerr<<l<<" "<<r<<endl;
		if(query(0,SIZE-1,1,0,l)<r)return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(*max_element(a+1,a+n+1)==1){
		puts("1");return 0;
	}
	for(int i=1;i<=n;i++)hd[i]=n+1;
	for(int i=n;i>=1;i--){
		nxt[i]=hd[a[i]];
		hd[a[i]]=i;
	}
	for(int i=1;i<=n;i++)occ[a[i]].push_back(i);
	for(int i=1;i<=n+1;i++){
		occ[i].push_back(0);
		occ[i].push_back(n+1);
		sort(occ[i].begin(),occ[i].end());
		if(!check(i)){
			cout<<i<<endl;
			return 0;
		}
		for(int j=1;j+1<occ[i].size();j++)update(occ[i][j],nxt[occ[i][j]]);
		update(occ[i][0],occ[i][1]);
	}
	cout<<n+2<<endl;
	return 0;
}