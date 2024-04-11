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
namespace bcj{
	int fa[600002];
	inline int findf(int x){
		return fa[x]==x?x:(fa[x]=findf(fa[x]));
	}
	inline void merge(int x,int y){
		fa[findf(x)]=findf(y);
	}
}
using bcj::findf;
struct ed{
	int x,y,z;
}e[300002];
inline bool cmp(const ed &x,const ed &y){
	return x.z<y.z;
}
int n,q,f[600002],fa[600002][20],v[600002],dfn[600002],cnt,c[600002][2],d[600002],id[600002];
inline void dfs(int pos){
	d[pos]=d[f[pos]]+1;
	fa[pos][0]=f[pos];
	F(i,1,19)fa[pos][i]=fa[fa[pos][i-1]][i-1];
	if(pos<=n){
		dfn[pos]=++cnt;
		id[cnt]=pos;
	}else{
		dfs(c[pos][0]);
		dfs(c[pos][1]);
	}
}
inline int lca(int x,int y){
	if(d[x]>d[y]){
		UF(i,19,0)if(d[fa[x][i]]>=d[y])x=fa[x][i];
	}else{
		UF(i,19,0)if(d[fa[y][i]]>=d[x])y=fa[y][i];
	}if(x==y)return x;
	UF(i,19,0)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return f[x];
}
namespace seg{
	int mmin[1200002],mmax[1200002],tag[1200002],minv[1200002],maxv[1200002];
	inline void puttag(int pos,int t){
		if(t==1){
			mmin[pos]=minv[pos],mmax[pos]=maxv[pos];
			tag[pos]=1;
		}else{
			mmin[pos]=1000000000,mmax[pos]=-1000000000;
			tag[pos]=2;
		}
	}
	inline void pushdown(int pos){
		if(tag[pos]){
			puttag(pos<<1,tag[pos]);
			puttag(pos<<1|1,tag[pos]);
			tag[pos]=0;
		}
	}
	inline void pushup(int pos){
		mmin[pos]=min(mmin[pos<<1],mmin[pos<<1|1]);
		mmax[pos]=max(mmax[pos<<1],mmax[pos<<1|1]);
	}
	#define mid ((l+r)>>1)
	inline void add(int pos,int l,int r,int ql,int qr,int t){
		if(ql<=l&&qr>=r){
			puttag(pos,t);
			return;
		}
		pushdown(pos);
		if(ql<=mid)add(pos<<1,l,mid,ql,qr,t);
		if(qr>mid)add(pos<<1|1,mid+1,r,ql,qr,t);
		pushup(pos);
	}
	inline int query(int x){
		if(mmin[1]>mmax[1])return -1;
		return max(v[lca(x,id[mmin[1]])],v[lca(id[mmin[1]],id[mmax[1]])]);
	}
	inline void build(int pos,int l,int r){
		mmin[pos]=1000000000,mmax[pos]=-1000000000;
		if(l==r){
			maxv[pos]=minv[pos]=dfn[l];
			return;
		}
		build(pos<<1,l,mid);
		build(pos<<1|1,mid+1,r);
		maxv[pos]=max(maxv[pos<<1],maxv[pos<<1|1]);
		minv[pos]=min(minv[pos<<1],minv[pos<<1|1]);
	}
}
int main() {
	cin>>n>>q;
	F(i,1,n+n-1)bcj::fa[i]=i,v[i]=-1;
	F(i,1,n-1)read(e[i].x,e[i].y,e[i].z);
	sort(e+1,e+n,cmp);
	F(i,1,n-1){
		f[c[n+i][0]=findf(e[i].x)]=n+i;
		f[c[n+i][1]=findf(e[i].y)]=n+i;
		v[n+i]=e[i].z;
		bcj::fa[bcj::fa[e[i].x]]=bcj::fa[bcj::fa[e[i].y]]=n+i;
	}
	dfs(n+n-1);
	seg::build(1,1,n);
	F(i,1,q){
		int t1=read(),t2=read();
		if(t1<=2)seg::add(1,1,n,t2,read(),t1);
		else write(seg::query(t2),'\n');
	}
	return 0;
}