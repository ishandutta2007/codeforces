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
ll mmax[200002],sz[200002],fa[200002],a[200002],t[200002],f[200002],big[200002],num,n,m,t1,t2,root,dp[200002],siz[200002],head[200002];
vector<int>g[200002],c[200002],co[200002],gg[200002],fk[200002];
bool vis[200002];
int mpos=0;
long double ans=1e99,qwq,qaq,quq;
inline void make_tree(int pos) {
	vis[pos]=1;
	dp[pos]=dp[f[pos]]+1;
	F(i,0,g[pos].size()-1)
	if(!vis[g[pos][i]]) {
		f[g[pos][i]]=pos;
		c[pos].push_back(g[pos][i]);
		make_tree(g[pos][i]);
	}
}
inline void getsize(int pos) {
	F(i,0,c[pos].size()-1) {
		getsize(c[pos][i]);
		siz[pos]+=siz[c[pos][i]];
	}
	siz[pos]++;
}
inline int lca(int x,int y) {
	while(head[x]!=head[y]) {
		if(dp[head[x]]<dp[head[y]]) {
			y=f[head[y]];
		} else {
			x=f[head[x]];
		}
	}
	if(dp[x]<dp[y])return x;
	else return y;
}
void dfs(int pos,bool isbig) {
	if(isbig)head[pos]=head[f[pos]];
	else head[pos]=pos;
	t[pos]=++num;
	ri mmax=0,mpos=0;
	F(i,0,c[pos].size()-1) {
		if(siz[c[pos][i]]>mmax) {
			mpos=c[pos][i];
			mmax=siz[c[pos][i]];
		}
	}
	big[pos]=mpos;
	if(c[pos].size())dfs(mpos,1);
	F(i,0,c[pos].size()-1)if(c[pos][i]!=mpos)dfs(c[pos][i],0);
}
inline void getmax(int pos,int fa) {
	sz[pos]=1;
	F(i,0,g[pos].size()-1) {
		if(g[pos][i]!=fa&&!vis[g[pos][i]]) {
			getmax(g[pos][i],pos);
			sz[pos]+=sz[g[pos][i]];
		}
	}
}
inline int findh(int pos,int fa,int tot) {
	ri rt=pos;
	mmax[pos]=tot-sz[pos];
	F(i,0,g[pos].size()-1) {
		if(!vis[g[pos][i]]&&g[pos][i]!=fa)mmax[pos]=max(mmax[pos],sz[g[pos][i]]);
	}
	F(i,0,g[pos].size()-1) {
		if(!vis[g[pos][i]]&&g[pos][i]!=fa) {
			ri nxt=findh(g[pos][i],pos,tot);
			if(mmax[rt]>mmax[nxt])rt=nxt;
		}
	}
	return rt;
}
inline int dfg(int pos) {
	getmax(pos,0);
	ri h=findh(pos,0,sz[pos]);
	vis[h]=1;
	F(i,0,g[h].size()-1) {
		if(!vis[g[h][i]]) {
			ri orz=dfg(g[h][i]);
			fa[orz]=h;
			gg[h].push_back(orz);
		} else gg[h].push_back(0);
	}
	return h;
}
inline void play(int pos,long double now) {
	vis[pos]=1;
	qwq+=a[pos]*pow(now,1.5);
	qaq+=a[pos]*pow(now+1,1.5);
	quq+=a[pos]*pow(now-1,1.5);
	F(i,0,g[pos].size()-1)if(!vis[g[pos][i]])play(g[pos][i],now+co[pos][i]);
}
inline void getans(int pos) {
	memset(vis,0,sizeof(vis));
	vis[pos]=1;
	qwq=qaq=quq=0;
	long double temp=a[pos];
	F(i,0,g[pos].size()-1) {
		play(g[pos][i],co[pos][i]);
		fk[pos].push_back(quq-qaq);
		//	cerr<<fk[pos].back()<<endl;
		temp+=qaq;
		qaq=quq=0;
	}
	if(qwq>=ans-1e-12) {
		//FUCK CCF
	} else {
		ans=qwq;
		mpos=pos;
	}
		long double qwqwq=1e99,qaqaq=0;
	F(i,0,g[pos].size()-1) {
		if(gg[pos][i]) {
			if(fk[pos][i]<qwqwq) {qwqwq=fk[pos][i],qaqaq=gg[pos][i];
				
			}
		}
	}if(qaqaq)getans(qaqaq);
}
int main() {
	cin>>n;
	F(i,1,n)a[i]=read();
	F(i,2,n) {
		t1=read(),t2=read();
		ri t3=read();
		g[t1].push_back(t2);
		g[t2].push_back(t1);
		co[t1].push_back(t3);
		co[t2].push_back(t3);
	}
	make_tree(1);
	getsize(1);
	dfs(1,0);
	memset(vis,0,sizeof(vis));
	root=dfg(1);
	getans(root);
	cout<<mpos<<' '<<fixed<<setprecision(114)<<ans;
	return 0;
}