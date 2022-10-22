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
#pragma GCC optimize(3)
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
	char _n_u_m_[40];
	template<class T>
	inline void write(T x ) {
		if(x==0) {
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
const int MAXN=10005,MAXM=10005;
int cnt=1,S,T,deep[MAXN],now[MAXN<<1];
int _cnt[1024],n,m,k,qwq,t1,t2,t3,uu[12],vv[12];
bool vis[MAXN];
short _v[1024][MAXM<<1],_nxt[1024][MAXM<<1],_to[1024][MAXM<<1],_head[1024][MAXN],head[MAXN],v[MAXM<<1],to[MAXM<<1],nxt[MAXM<<1];
inline void save(int pos) {
	_cnt[pos]=cnt;
	memcpy(_head[pos],head,sizeof(head));
	memcpy(_to[pos],to,sizeof(to));
	memcpy(_v[pos],v,sizeof(v));
	memcpy(_nxt[pos],nxt,sizeof(nxt));
}
inline void cpy(int pos) {
	cnt=_cnt[pos];
	memcpy(head,_head[pos],sizeof(head));
	memcpy(to,_to[pos],sizeof(to));
	memcpy(v,_v[pos],sizeof(v));
	memcpy(nxt,_nxt[pos],sizeof(nxt));
}
inline void add(int x,int y,int vv) {
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
	v[cnt]=vv;
}
inline void ed(int x,int y,int vv) {
	add(x,y,vv);
	add(y,x,0);
}
inline bool bfs() {
	memset(deep,0,sizeof(deep));
	deep[S]=1;
	queue<int>q;
	q.push(S);
	ri h;
	while(!q.empty()) {
		h=q.front();
		q.pop();
		now[h]=head[h];
		for(ri i=head[h]; i; i=nxt[i]) {
			if(!deep[to[i]]&&v[i]>0) {
				q.push(to[i]);
				deep[to[i]]=deep[h]+1;
			}
		}
	}
	return deep[T];
}
inline int dfs(int pos,int mmax) {
	if(pos==T)return mmax;
	ri rt=0;
	for(ri i=now[pos]; i&&mmax; i=nxt[i]) {
		now[pos]=i;
		if(deep[to[i]]==deep[pos]+1&&v[i]>0) {
			ri k=dfs(to[i],min(mmax,(int)v[i]));
			if(k==0)deep[to[i]]=INT_MAX-2;
			else {
				rt+=k;
				mmax-=k;
				v[i]-=k;
				v[i^1]+=k;
			}
		}
	}
	return rt;
}
inline int Dinic() {
	ri rt=0;
	while(bfs()) {
		rt+=dfs(S,25);
	}
	return rt;
}
int K;
#include<assert.h>
int q[10002],l,r;
inline int FF_bfs() {
	l=1,r=1;
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	q[1]=1;
	ri pos,orz;
	while(l<=r){
		pos=q[l++];
		for(ri i=head[pos];i;i=nxt[i]){
			orz=to[i];
			if(v[i]&&!vis[orz]){
				vis[orz]=1;
				now[orz]=i;
				q[++r]=orz;
				if(orz==n)break;
			}
		}
		if(vis[n])break;
	}
	if(!vis[n])return 0;
	re short mmin=25;
	for(ri i=n;i^1;i=to[now[i]^1])mmin=(mmin<v[now[i]]?mmin:v[now[i]]);
	for(ri i=n;i^1;i=to[now[i]^1])v[now[i]]-=mmin,v[now[i]^1]+=mmin;
	return mmin;
}
inline int FF() {
	int temp=0,rt=0;
	while((temp=FF_bfs())) {
		rt+=temp;
	}
	return rt;
}
int f[1024],base,dp[1024],low[1024];
int main() {
	cin>>n>>m>>k>>qwq;
	m-=k,S=1,T=n,K=(1<<k)-1;
	F(i,1,1023)low[i]=((i&1)?0:low[i>>1]+1);
	F(i,1,k) {
		read(uu[i-1]);
		read(vv[i-1]);
		read();
	}
	F(i,1,m) {
		read(t1);
		read(t2);
		read(t3);
		ed(t1,t2,t3);
	}
	f[0]=Dinic();
	save(0);
	F(i,1,(1<<k)-1) {
		cpy(i^(-i&i));
		ed(uu[low[i]],vv[low[i]],25);
		f[i]=f[i^(-i&i)]+FF();
		save(i);
	}
	F(iakioi,1,qwq) {
		F(i,0,k-1)read(dp[1<<i]);
		int ans=f[K];
		F(i,1,(1<<k)-1) {
			if(i!=(-i&i)) {
				dp[i]=dp[-i&i]+dp[i^(-i&i)];
			}
			ans=min(ans,dp[i]+f[K^i]);
		}
		write(ans,'\n');
	}
	return 0;
}