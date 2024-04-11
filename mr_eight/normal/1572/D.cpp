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
int cnt=1,S,T,SS,head[MAXN],deep[MAXN],to[MAXM<<1],v[MAXM<<1],nxt[MAXM<<1],flow[MAXN],cost[MAXM<<1],n,m,lst[MAXN],pre[MAXN];
int a[1<<20],p[1<<20],k;
pii ak[114514];
bool viss[1<<20];
vector<pii >orz[2000002];
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
}inline void ed(int x,int y,int vv,int qwq){qwq=-qwq;
	add(x,y,vv,qwq);
	add(y,x,0,-qwq);
}queue<int>q;
bool vis[MAXN];
#define dis deep
#define vec orz
bool spfa(){ri pos=S;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(flow,0x3f,sizeof(flow));
	q.push(pos);
	vis[pos]=1;
	dis[pos]=0;
	int nx;
	while(!q.empty()){
		pos=q.front(),q.pop(),vis[pos]=0;
		for(register int i=head[pos];i;i=nxt[i]){
			nx=to[i];
			if(v[i]>0&&dis[nx]>dis[pos]+cost[i]){
				lst[nx]=i;
				pre[nx]=pos;
				dis[nx]=dis[pos]+cost[i];
				flow[nx]=min(flow[pos],v[i]);
				if(!vis[nx])vis[nx]=1,q.push(nx);
			}
		}
	}return dis[T]<0;
}
inline int Dinic(){
	int rt1=0;
	while(spfa()){
		ri now=T;
		rt1+=flow[T]*dis[T];
		while(now!=S){
			v[lst[now]]-=flow[T];
			v[lst[now]^1]+=flow[T];
			now=pre[now];
		}
	}
	return -rt1;
}
int main(){
	T=50001;SS=T-1;
	/*
	read(n),read(m),read(S),read(T);
	F(qwq,1,m){
		ri t1=read(),t2=read(),t3=read(),t4=read();
		ed(t1,t2,t3,t4);
	}
	*/
	cin>>n>>k;
	F(i,0,(1<<n)-1){
		read(a[i]);
	}
	F(k,0,n-1){
		F(j,0,(1<<n)-1)if(j>>k&1){
			vec[a[j]+a[j^(1<<k)]].push_back(make_pair(j^(1<<k),j));
		}
	}
	#define cnt cntt
	int cntt=0;
	UF(i,2000000,0){
		for(pii j:vec[i]){
			viss[j.first]=viss[j.second]=true;
			if(__builtin_popcount(j.first)&1)ak[++cnt]=make_pair(j.second,j.first);
			else ak[++cnt]=make_pair(j.first,j.second);
			if(cnt==k*(2*n-1)+1)goto iakioi;
		}
	}
	iakioi:;
	int tott=cntt;
	cnt=0;
	F(i,0,(1<<n)-1){
		if(viss[i]){
			p[i]=++cnt;
			if(__builtin_popcount(i)&1)ed(cnt,T,1,a[i]);
			else ed(SS,cnt,1,a[i]);
		}
	}
	#undef cnt
	F(i,1,tott)ed(p[ak[i].first],p[ak[i].second],1,0);
	ed(S,SS,k,0);
	cout<<Dinic();
	return 0;
}