/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
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
int n,m,k;
set<pair<int,int> >s;
multiset<int>s2;
#define SIZE 1048576
int f[SIZE<<1],g[SIZE<<1];
void init(){
	memset(g,0,sizeof g);
	for(int i=0;i<SIZE;i++)f[i+SIZE]=i-1;
	for(int i=SIZE-1;i>=1;i--){
		f[i]=max(f[i<<1],f[i<<1|1]);
	}
}
void pushdown(int id){
	g[id<<1]+=g[id];
	g[id<<1|1]+=g[id];
	g[id]=0;
}
void pushup(int id){
	f[id]=max(f[id<<1]+g[id<<1],f[id<<1|1]+g[id<<1|1]);
}
void add(int l,int r,int id,int ql,int qr,int v){
	if(qr<l||r<ql)return;
	if(ql<=l&&r<=qr){
		g[id]+=v;
		return;
	}
	pushdown(id);
	add(l,(l+r)/2,id<<1,ql,qr,v);
	add((l+r)/2+1,r,id<<1|1,ql,qr,v);
	pushup(id);
}
int query(int l,int r,int id,int ql,int qr){
	if(qr<l||r<ql)return -inf;
	if(ql<=l&&r<=qr){
		return f[id]+g[id];
	}
	pushdown(id);
	int vl=query(l,(l+r)/2,id<<1,ql,qr);
	int vr=query((l+r)/2+1,r,id<<1|1,ql,qr);
	pushup(id);
	return max(vl,vr);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k>>m;
	init();
	while(m--){
		int x,y;cin>>x>>y;
		int neg;
		if(s.count(make_pair(x,y))){
			neg=-1;
			s2.erase(s2.find(y+abs(k-x)));
			s.erase(make_pair(x,y));
		}else{
			neg=1;
			s.insert(make_pair(x,y));
			s2.insert(y+abs(k-x));
		}
		add(0,SIZE-1,1,1,y+abs(x-k),neg);
		if(!s2.size()){
			cout<<0<<endl;
			continue;
		}
		int ans=query(0,SIZE-1,1,1,*s2.rbegin());
		if(ans>n)cout<<ans-n<<endl;
		else cout<<0<<endl;
	}
	return 0;
}