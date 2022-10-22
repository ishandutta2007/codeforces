//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
//#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
using namespace std;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
namespace fastIO {
	template<class T>
	inline void read(T &x) {
		x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		if(fu)x=-x;
	}
	inline int read() {
		int x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		return fu?-x:x;
	}
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
	}
	char _n_u_m_[40];
	template<class T>
	inline void write(T x) {
		if(x==0){
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		register int cnt = 0 ;
		while( tmp > 0 ) {
			_n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
	}
	template<class T>
	inline void write(T x ,char ch) {
		write(x);
		putchar(ch);
	}
}
using namespace fastIO;
int n,k,fa[200002],t1,t2,d[200002],t[200002],cnt,mmax[800002],tag[800002],p[200002],sz[200002];
vector<int>g[200002];
bool vis[200002];
inline void dfs(int pos,int f){
	fa[pos]=f;d[pos]=d[f]+1;t[pos]=++cnt;p[cnt]=pos;bool flag=false;sz[pos]=1;
	for(int i:g[pos])if(i!=f)dfs(i,pos),flag=true,sz[pos]+=sz[i];if(flag)d[pos]=-1000000000;
}
#define mid (l+r>>1)
inline void build(int pos,int l,int r){
	if(l==r){
		mmax[pos]=d[p[l]];
		return;
	}
	build(pos<<1,l,mid);build(pos<<1|1,mid+1,r);
	mmax[pos]=max(mmax[pos<<1],mmax[pos<<1|1]);
}
inline void pd(int pos){
	if(tag[pos]){
		mmax[pos<<1]+=tag[pos];mmax[pos<<1|1]+=tag[pos];
		tag[pos<<1]+=tag[pos];tag[pos<<1|1]+=tag[pos];
		tag[pos]=0;
	}
}
inline void mns(int pos,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){
		--mmax[pos];
		--tag[pos];
		return;
	}
	pd(pos);
	if(ql<=mid)mns(pos<<1,l,mid,ql,qr);
	if(qr>mid)mns(pos<<1|1,mid+1,r,ql,qr);
	mmax[pos]=max(mmax[pos<<1],mmax[pos<<1|1]);
}
inline int query(int pos,int l,int r){
	if(l==r){
		mmax[pos]=-1000000000;
		return l;
	}
	pd(pos);
	if(mmax[pos<<1]==mmax[pos]){
		int rt=query(pos<<1,l,mid);
		mmax[pos]=max(mmax[pos<<1],mmax[pos<<1|1]);
		return rt;
	}else{
		int rt=query(pos<<1|1,mid+1,r);
		mmax[pos]=max(mmax[pos<<1],mmax[pos<<1|1]);
		return rt;
	}
}
int tot;
ll ans=LLONG_MAX;
int main() {
	cin>>n>>k;
	F(i,2,n){
		read(t1);read(t2);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	dfs(1,0);
	build(1,1,n);//F(i,1,n)cerr<<p[i]<<" "<<d[p[i]]<<endl;
	vis[0]=true;
	F(i,1,k){
		int x=p[query(1,1,n)];
		if(d[x]<0){
			ll ans=0;
			F(j,tot,k)ans=max(ans,j*1ll*(n-j));
			cout<<ans;
			return 0;
		}
		++tot;
		d[x]=-1000000000;
		for(;!vis[x];x=fa[x])vis[x]=true,mns(1,1,n,t[x],t[x]+sz[x]-1);
	}int sum=tot;ans=min(ans,(n-sum)*1ll*tot);
	F(i,1,n)if(!vis[i])--tot,++sum,ans=min(ans,(n-sum)*1ll*tot);
	//sum=n-sum;
	cout<<ans;
	return 0;
}