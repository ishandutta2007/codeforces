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
#define int long long
//#pra gma G CC opti mize(3)
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
const int MAXN=50002,MAXM=100002;
const int MAXQ=1000000;
int a[MAXN],cnt=1,S,T=MAXN-1,head[MAXN],deep[MAXN],to[MAXM<<1],v[MAXM<<1],nxt[MAXM<<1],flow[MAXN],cost[MAXM<<1],n,m,lst[MAXN],pre[MAXN];
inline void clear(){
	cnt=1;
	memset(head,0,sizeof(head));
	memset(deep,0,sizeof(deep));
	memset(to,0,sizeof(to));
	memset(v,0,sizeof(v));
	memset(nxt,0,sizeof(nxt));
	memset(flow,0,sizeof(flow));
	memset(cost,0,sizeof(cost));
	memset(lst,0,sizeof(lst));
	memset(pre,0,sizeof(pre));
}
inline void add(int x,int y,int vv,int qwq){
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
	v[cnt]=vv;
	cost[cnt]=qwq;
}inline void ed(int x,int y,int vv,int qwq){
	add(x,y,vv,qwq);
	add(y,x,0,-qwq);
}
int que[MAXQ],q_l,q_r;
bool vis[MAXN];
#define dis deep
bool spfa(){ri pos=S;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(flow,0x3f,sizeof(flow));
	q_l=q_r=1;
	que[1]=pos;
	vis[pos]=1;
	dis[pos]=0;
	int nx;
	while(q_l<=q_r){
		pos=que[q_l];
		++q_l;
		vis[pos]=0;
		for(register int i=head[pos];i;i=nxt[i]){
			nx=to[i];
			if(v[i]>0&&dis[nx]>dis[pos]+cost[i]){
				lst[nx]=i;
				pre[nx]=pos;
				dis[nx]=dis[pos]+cost[i];
				flow[nx]=min(flow[pos],v[i]);
				if(!vis[nx])vis[nx]=1,que[++q_r]=nx;
			}
		}
	}return dis[T]<=1e15;
}
inline void Dinic(){
	ri rt1=0;
	while(spfa()){
		ri now=T;
		if(dis[T]>=0)return;
		rt1+=flow[T]*dis[T];
		while(now!=S){
			v[lst[now]]-=flow[T];
			v[lst[now]^1]+=flow[T];
			now=pre[now];
		}
	}
	return;
}
signed main(){
	cin>>n>>m;
	F(i,1,n)read(a[i]);
	F(i,1,n)ed(S,i,1,0),ed(i,T,1,0);
	F(i,1,m){
		int x=read(),y=read();
		ed(x,y,114514,a[y]-a[x]);
	}
	Dinic();
	F(i,1,n)write(a[i]-dis[i],' ');
	return 0;
}