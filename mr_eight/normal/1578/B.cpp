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
const int MAXN=100002,MAXM=1000002;
int cnt=1,S,T=MAXN-1,head[MAXN],deep[MAXN],to[MAXM<<1],v[MAXM<<1],nxt[MAXM<<1],now[MAXN<<1];
inline void clear() {
	cnt=1;
	S=T=0;
	memset(head,0,sizeof(head));
	memset(deep,0,sizeof(deep));
	memset(to,0,sizeof(to));
	memset(v,0,sizeof(v));
	memset(nxt,0,sizeof(nxt));
	memset(now,0,sizeof(now));
}
inline void add(int x,int y,int vv) {
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
	v[cnt]=vv;
}
inline void ed(int x,int y,int vv=1) {
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
			ri k=dfs(to[i],min(mmax,v[i]));
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
		rt+=dfs(S,INT_MAX);
	}
	return rt;
}
bool vis[502][502],tot[502],tag[502][502];
char c[502][502];
#define cnt ad
int n,m,cnt;
int main() {
	cin>>n>>m;
	F(i,1,n) {
		scanf("%s",c[i]+1);
		F(j,1,m)vis[i][j]=(c[i][j]=='B');
	}
	UF(i,n,1) {
		UF(j,m,1) {
			if(vis[i][j]^tot[j]) {
				tag[i][j]=1;
				++cnt;
				F(k,1,j)tot[k]^=1;
			}
		}
	}
	F(i,1,n-1)ed(S,i);
	F(i,n+1,n+m-1)ed(i,T);
	F(i,1,n-1)if(tag[i][m])F(j,1,m-1)if(tag[n][j])if(tag[i][j])ed(i,j+n);
	int f=Dinic();
	if(f%2==tag[n][m])write(cnt-f-tag[n][m]);
	else {
		if(tag[n][m]){
			write(cnt-f);
			return 0;
		}else{
			write(cnt-f+1);
		}
		/*
		clear();
		T=MAXN-1;
		F(i,1,n-1)ed(S,i);
		F(i,n+1,n+m-1)ed(i,T);
		F(i,1,n-1)if(tag[i][m])F(j,1,m-1)if(tag[n][j])if(tag[i][j])ed(i,j+n);
		F(i,1,n-1)if(tag[i][m]){
			bool tar=false;
			F(j,1,m-1)tar|=tag[i][j];
			if(tar)ed(i,n);
		}
		F(j,1,m-1)if(tag[n][j]){
			bool tar=false;
			F(i,1,n-1)tar|=tag[i][j];
			if(tar)ed(j+n,n);
		}
		ed(n,T);
		int ff=Dinic();
		if(ff==f){
			
		}
		write(cnt-f);
		*/
	}
	return 0;
}