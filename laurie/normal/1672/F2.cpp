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
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
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
const int MAXN=200005,MAXM=800005;
int head[MAXN],nxt[MAXM],n,m,to[MAXM],x,y,deg[MAXN],sta[MAXM],cnt;
bool vis[MAXM>>1];
int tp,lst[MAXN];
inline void dfs2(int pos) {
	for(int &e=head[pos]; e; e=nxt[e]) {
		if(vis[e])continue;
		int temp=e;
		vis[e]=1;
		dfs2(to[e]);
		sta[++cnt]=pos;
	}
}
int a[200002],b[200002],num[MAXN],c[200002],dfn[200002];
vector<int>g[MAXN];
inline bool dfs(int pos,int t){
	if(dfn[pos]){
		return !vis[pos];
	}
	dfn[pos]=t;
	vis[pos]=true;
	for(int i:g[pos])if(!dfs(i,t))return false;
	vis[pos]=false;
	return true;
}
int main() {
	tp=2;
	F(iakioi,1,read()) {
		read(n);
		m=n;
		F(i,1,n)deg[i]=head[i]=num[i]=lst[i]=vis[i]=0,g[i].clear();
		F(i,1,n) {
			read(a[i]);
			++num[a[i]];
		}
		F(i,1,n)read(b[i]);
		F(i,1,n) {
			x=a[i],y=b[i];
			++deg[x],--deg[y];
			to[i]=y;
			nxt[i]=head[x];
			head[x]=i;
		}cnt=0;
		int I=0;
			int i=max_element(num+1,num+n+1)-num;
			I=i;
			dfs2(i);
		if(cnt!=m){
			puts("WA");
		}
		else {
			//	puts("YES");
			reverse(sta+1,sta+n+1);
			int id=0;
			bool flag=false;
			F(i,1,n) {
				if(sta[i]==I)++id;
				else {
					if(lst[sta[i]]==id) {
						puts("WA");
						flag=true;
						break;
					}
					lst[sta[i]]=id;
					if(sta[i-1]!=I)g[sta[i-1]].push_back(sta[i]);
				}
			}F(i,1,n)dfn[i]=vis[i]=0;int t=0;
			if(!flag)F(i,1,n){
				if(!dfn[i]){
					++t;
					if(!dfs(i,t)){
						puts("WA");
						flag=true;
						break;
					}
				}
			}
			if(!flag)puts("AC");
		}
	}

	return 0;
}
/*
4
1 2 3 3
2 3 3 1
*/