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
int cnt=1,S,T,head[MAXN],deep[MAXN],to[MAXM<<1],v[MAXM<<1],nxt[MAXM<<1],flow[MAXN],cost[MAXM<<1],n1,n2,m,lst[MAXN],pre[MAXN],ans;
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
	if(!vv)return;
	add(x,y,vv,qwq);
	add(y,x,0,-qwq);
}
inline void ed(int x,int y,int l,int r,int qwq){
	ed(x,y,l,qwq-1000000000);
	ed(x,y,r-l,qwq);
	ans+=l*1000000000;
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
	}
	return dis[T]<=1e17;
}
inline int Dinic(){
	ri rt0=0,rt1=0;
	while(spfa()){
		ri now=T;
		rt0+=flow[T];
		if(dis[T]>=0)break;
		rt1+=flow[T]*dis[T];
		while(now!=S){
			v[lst[now]]-=flow[T];
			v[lst[now]^1]+=flow[T];
			now=pre[now];
		}
	}
	return rt1;
}
inline char ak(){
	char ch=getchar();
	while(ch<'A'||ch>'Z')ch=getchar();
	return ch;
}
int a[MAXN],b[MAXN];
signed main(){
	read(n1),read(n2),read(m),S=0,T=MAXN-1;
	int R=read(),B=read();
	F(i,1,n1){
		char c=ak();
		if(c=='R')ed(i,T,1,200,0);
		else if(c=='B')ed(S,i,1,200,0);
		else ed(S,i,200,0),ed(i,T,200,0);
	}
	F(i,n1+1,n1+n2){
		char c=ak();
		if(c=='B')ed(i,T,1,200,0);
		else if(c=='R')ed(S,i,1,200,0);
		else ed(S,i,200,0),ed(i,T,200,0);
	}
	F(i,1,m){
		int x=read(),y=read()+n1;
		ed(x,y,1,B);
		b[i]=cnt;
		ed(y,x,1,R);
		a[i]=cnt;
	}
	ans+=Dinic();
	if(ans<1e5){
		write(ans,'\n');
		F(i,1,m){
			if(v[a[i]])putchar('R');
			else if(v[b[i]])putchar('B');
			else putchar('U');
		}
	}else puts("-1");
	return 0;
}