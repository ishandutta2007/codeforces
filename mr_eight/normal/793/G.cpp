//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <math.h>
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
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
using namespace std;
using std::bitset;
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
	inline void write(T x ) {
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
int n,q;
const int MAXN=1000002,MAXM=1000002;
int cnt=1,S,T,head[MAXN],deep[MAXN],to[MAXM<<1],v[MAXM<<1],nxt[MAXM<<1],now[MAXN<<1];
inline void clear(){
	cnt=1;
	S=T=0;
	memset(head,0,sizeof(head));
	memset(deep,0,sizeof(deep));
	memset(to,0,sizeof(to));
	memset(v,0,sizeof(v));
	memset(nxt,0,sizeof(nxt));
	memset(now,0,sizeof(now));
}
inline void add(int x,int y,int vv){
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
	v[cnt]=vv;
}inline void ed(int x,int y,int vv){
	add(x,y,vv);
	add(y,x,0);
}
inline void ed2(int x,int y,int vv){
	add(x,y,vv);
	add(y,x,vv);
}
inline bool bfs(){
	memset(deep,0,sizeof(deep));
	deep[S]=1;
	queue<int>q;
	q.push(S);
	ri h;
	while(!q.empty()){
		h=q.front();
		q.pop();
		now[h]=head[h];
		for(ri i=head[h];i;i=nxt[i]){
			if(!deep[to[i]]&&v[i]>0){
				q.push(to[i]);
				deep[to[i]]=deep[h]+1;
			}
		}
	}return deep[T];
}
inline int dfs(int pos,int mmax){
	if(pos==T)return mmax;
	ri rt=0;
	for(ri i=now[pos];i&&mmax;i=nxt[i]){
		now[pos]=i;
		if(deep[to[i]]==deep[pos]+1&&v[i]>0){
			ri k=dfs(to[i],min(mmax,v[i]));			
			if(k==0)deep[to[i]]=INT_MAX-2;
			else{
				rt+=k;
				mmax-=k;
				v[i]-=k;
				v[i^1]+=k;
			}
		}
	}return rt;
}
inline int Dinic(){
	ri rt=0;
	while(bfs()){
		rt+=dfs(S,INT_MAX);
	}return rt;
}
#define now fuck_ccf
int tot,now;
inline int id(int x,int y){
	return (x-1)*n+y;
}
int lc[1000002],rc[1000002],root[1000002];
vector<pii>orz[10002],sto[10002];
#define mid (l+r>>1)
inline int build(int pos,int l,int r){
	if(l==r){
		--now;
		ed(now,l,1e9);
	}else{
		int qwq=build(pos<<1,l,mid);
		int qaq=build(pos<<1|1,mid+1,r);
		--now;
		ed(now,qwq,1e9);
		ed(now,qaq,1e9);
		lc[now]=qwq,rc[now]=qaq;
		return now;
	}
	return now;
}
inline int ins(int lst,int r0,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r)return r0;
	if(ql>r||qr<l)return lst;
	int qwq=ins(lc[lst],lc[r0],l,mid,ql,qr);
	int qaq=ins(rc[lst],rc[r0],mid+1,r,ql,qr);
	--now;
	lc[now]=qwq,rc[now]=qaq;
	ed(now,qwq,1e9);
	ed(now,qaq,1e9);
	return now;
}
inline int era(int lst,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r)return n+1;
	if(ql>r||qr<l)return lst;
	int qwq=era(lc[lst],l,mid,ql,qr);
	int qaq=era(rc[lst],mid+1,r,ql,qr);
	--now;
	lc[now]=qwq,rc[now]=qaq;
	ed(now,qwq,1e9);
	ed(now,qaq,1e9);
	return now;
}
inline void db(int pos,int l,int r){
	cout<<pos<<' '<<l<<' '<<r<<endl;
	if(l!=r){
		db(lc[pos],l,mid);
		db(rc[pos],mid+1,r);
	}
}
int main() {
	T=1000000;now=T;
	cin>>n>>q;
	root[0]=build(1,1,n);
	lc[n+1]=rc[n+1]=n+1;
	F(i,1,n)ed(i,T,1);
	F(i,1,q){
		int t1,t2,t3,t4;
		read(t1,t2,t3,t4);
		orz[t1].push_back(make_pair(t2,t4));
		sto[t3+1].push_back(make_pair(t2,t4));
	}
	int fuck=0;
	F(i,1,n){
		for(auto x:sto[i]){
			++fuck;
			root[fuck]=ins(root[fuck-1],root[0],1,n,x.first,x.second);
		}
		for(auto x:orz[i]){
			++fuck;
			root[fuck]=era(root[fuck-1],1,n,x.first,x.second);
		}
		ed(0,root[fuck],1);
		//db(root[fuck],1,n);cerr<<endl;
	}
	cout<<Dinic();
	return 0;
}