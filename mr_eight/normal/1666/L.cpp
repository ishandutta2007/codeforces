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
const int MAXN=1000002;
int dfn[MAXN],low[MAXN],dfn_num,sta[MAXN],top,tot,n,m,qwq[MAXN];
vector<int>g[MAXN],num[MAXN];
void Tarjan(int u,int fa){
    dfn[u]=low[u]=++dfn_num;
    sta[++top]=u;
    F(i,0,g[u].size()-1){
    	ri v=g[u][i];
		if(v==fa)continue;
        if(!dfn[v]){
            Tarjan(v,u);
			low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                ++tot;
                while(sta[top+1]!=v) num[tot].push_back(sta[top]),--top;
                num[tot].push_back(u);
            }
        }
        else low[u]=min(low[u],dfn[v]);
    }
}
int dp[MAXN],fa[MAXN],s;
vector<int>a,b;
inline void getans(int x,int y,int z){int xx=x,yy=y;
	puts("Possible");
	while(x!=s)a.push_back(x),x=fa[x];
	while(y!=s)b.push_back(y),y=fa[y];
	a.push_back(s),b.push_back(s);
	reverse(a.begin(),a.end());reverse(b.begin(),b.end());x=xx,y=yy;
int i=z;
			a.push_back(i);
			b.push_back(i);
			write(a.size(),'\n');
			for(int ii:a)write(ii,' ');puts("");
			write(b.size(),'\n');
			for(int ii:b)write(ii,' ');puts("");return;
}
int NOW;
int t[MAXN];
inline void dfs(int pos,int lst){
	if(pos==s)return;
	if(fa[pos]&&t[pos]!=NOW){
		getans(fa[pos],lst,pos);
		exit(0);
	}else if(fa[pos])return;
	fa[pos]=lst;t[pos]=NOW;
	for(int i:g[pos])dfs(i,pos);
}
int main() {
	cin>>n>>m>>s;
	F(i,1,m){
		ri t1=read(),t2=read();
		g[t1].push_back(t2);
	}
	for(int i:g[s])++NOW,dfs(i,s);puts("Impossible");
	return 0;
}
/*
4 6 1
1 2
2 3
1 4
3 4
3 1
3 2
*/