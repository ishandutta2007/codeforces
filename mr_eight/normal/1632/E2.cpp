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
using namespace std;
int t[300002],f[300002],sz[300002],
    dp[300002],head[300002],big[300002],root=1,n,m,t1,t2,t3,num,qwqwqwq,p,x,y,z;
vector<int>c[300002],g[300002];
bool vis[300002];
inline void make_tree(int pos) {
	vis[pos]=1;
	dp[pos]=dp[f[pos]]+1;
	sz[pos]=1;
	F(i,0,g[pos].size()-1)
	if(!vis[g[pos][i]]) {
		f[g[pos][i]]=pos;
		c[pos].push_back(g[pos][i]);
		make_tree(g[pos][i]);
		sz[pos]+=sz[g[pos][i]];
	}
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
inline int dis(int x,int y) {
	if(!x||!y)return 0;
	return dp[x]+dp[y]-(dp[lca(x,y)]<<1);
}
void dfs(int pos,bool isbig) {
	if(isbig)head[pos]=head[f[pos]];
	else head[pos]=pos;
	t[pos]=++num;
	ri mmax=0,mpos=0;
	F(i,0,c[pos].size()-1) {
		if(sz[c[pos][i]]>mmax) {
			mpos=c[pos][i];
			mmax=sz[c[pos][i]];
		}
	}
	big[pos]=mpos;
	if(c[pos].size())dfs(mpos,1);
	F(i,0,c[pos].size()-1)if(c[pos][i]!=mpos)dfs(c[pos][i],0);
}
int ans[300002],res[300002];
pii a[300002];
int main() {
	root=1;
	dp[0]=-1;
	F(iakioi,1,read()) {
		cin>>n;
		F(i,1,n) {
			g[i].clear();
			c[i].clear();
			vis[i]=t[i]=f[i]=dp[i]=head[i]=big[i]=0;
		}
		F(i,2,n) {
			t1=read(),t2=read();
			g[t1].push_back(t2);
			g[t2].push_back(t1);
		}
		make_tree(root);
		dfs(root,0);
		F(i,1,n)a[i]=make_pair(dp[i],i);
		sort(a+1,a+n+1);
		int now=n+1,x=0,y=0;
		UF(i,n,0){
			while(now>1&&a[now-1].first==i+1){
				int pos=a[--now].second;
				if(!x){
					x=y=pos;
				}
				int lst=dis(x,y),qwq=dis(x,pos),qaq=dis(y,pos);
				if(qwq<qaq){
					if(qaq>lst)x=pos;
				}else{
					if(qwq>lst)y=pos;
				}
			}
			int len=(dis(x,y)+1)>>1;
			if(x)res[i]=i-len;//cerr<<x<<" "<<y<<" "<<dis(x,y)<<" "<<res[i]<<endl;
			else res[i]=1e9;
		}
		now=n;
		UF(i,n,1){
			while(now>0&&res[now-1]>=i)--now;
			ans[i]=now;
		}
		F(i,1,n)write(ans[i],' ');puts("");
	}


	return 0;
}