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
map<int,int>mp;
int q,t[100005],x[100005],y[100005],par[100005],l[100005],r[100005];
int find(int x){return x==par[x]?x:par[x]=find(par[x]);}
#define SIZE 262144
vector<int>id[SIZE<<1];
void solve(int l,int r,int k,int pos,int val){
	if(id[k].size()){
		for(auto v:id[k]){
			::l[val]=min(::l[val],::l[find(v)]);
			::r[val]=max(::r[val],::r[find(v)]);
			par[find(v)]=val;
		}
		id[k].clear();
		id[k].push_back(val);
	} 
	if(l==r)return;
	int mid=(l+r)/2;
	if(pos<=mid)solve(l,mid,k<<1,pos,val);
	else solve(mid+1,r,k<<1|1,pos,val);
}
void update(int l,int r,int k,int ql,int qr,int qv){
	if(qr<l||r<ql)return;
	if(ql<=l&&r<=qr){
		id[k].push_back(qv);
		return;
	}
	update(l,(l+r)/2,k<<1,ql,qr,qv);
	update((l+r)/2+1,r,k<<1|1,ql,qr,qv);
}
int main(){
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d%d",&t[i],&x[i],&y[i]);
		if(t[i]==1)mp[x[i]],mp[y[i]];
	}
	int van=0;
	for(auto &p:mp)p.second=++van;
	for(int i=1;i<=q;i++)if(t[i]==1){
		x[i]=mp[x[i]];y[i]=mp[y[i]];
	}
	for(int i=1;i<=q;i++)par[i]=i;
	for(int i=0;i<(SIZE*2);i++)id[i].clear();
	int tot=0;
	for(int i=1;i<=q;i++){
		if(t[i]==1){
			++tot;l[tot]=x[i];r[tot]=y[i];
			solve(0,SIZE-1,1,x[i],tot);
			solve(0,SIZE-1,1,y[i],tot);
			if(x[i]+1<=y[i]-1)update(0,SIZE-1,1,x[i]+1,y[i]-1,tot);
		}else{
//			cerr<<x[i]<<" "<<y[i]<<" "<<find(x[i])<<" "<<find(y[i])<<endl;
//			cerr<<l[x[i]]<<" "<<r[x[i]]<<" "<<l[y[i]]<<" "<<r[y[i]]<<endl;
			x[i]=find(x[i]);y[i]=find(y[i]);
			if(x[i]==y[i])puts("YES");
			else if(l[y[i]]<l[x[i]]&&l[x[i]]<r[y[i]])puts("YES");
			else if(l[y[i]]<r[x[i]]&&r[x[i]]<r[y[i]])puts("YES");
			else puts("NO");
		}
	}
	return 0;
}