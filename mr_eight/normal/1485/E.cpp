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
const int MAXN=200002;
int n,t1,t2,f[MAXN],d[MAXN];
vector<int>c[MAXN];
bool vis[MAXN];
ll dp[MAXN][2],ans,mmax[MAXN],mmin[MAXN],g[MAXN][2],a[MAXN];
inline bool cmp(ri x,ri y) {
	return a[x]<a[y];
}
queue<int>q;
inline void bfs() {
	ri pos=1;
	q.push(1);
	while(!q.empty()) {
		pos=q.front();
		q.pop();
		d[pos]=d[f[pos]]+1;
		mmax[d[pos]]=max(mmax[d[pos]],a[pos]);
		mmin[d[pos]]=min(mmin[d[pos]],a[pos]);
		F(i,0,c[pos].size()-1)q.push(c[pos][i]);
	}q.push(1);
	while(!q.empty()) {
		pos=q.front();
		q.pop();
		if(c[pos].empty()) {
			ans=max(ans,max(dp[d[pos]-1][0]+a[pos],dp[d[pos]-1][1]-a[pos]));
			continue;
		}
		if(c[pos].size()>1)sort(c[pos].begin(),c[pos].end(),cmp);
if(pos!=1){
	

		g[pos][0]=max(g[pos][0],max(dp[d[pos]-1][0]+a[pos]-a[c[pos][0]],dp[d[pos]-1][1]-a[pos]-a[c[pos][0]]));
		g[pos][1]=max(g[pos][1],max(dp[d[pos]-1][0]+a[pos]+a[c[pos][c[pos].size()-1]],dp[d[pos]-1][1]-a[pos]+a[c[pos][c[pos].size()-1]]));
		g[pos][0]=max(g[pos][0],g[f[pos]][0]+a[c[f[pos]][0]]-a[pos]+mmax[d[pos]]-a[c[pos][0]]);
		g[pos][0]=max(g[pos][0],g[f[pos]][1]-a[c[f[pos]][c[f[pos]].size()-1]]+a[pos]-mmin[d[pos]]-a[c[pos][0]]);
		g[pos][1]=max(g[pos][1],g[f[pos]][0]+a[c[f[pos]][0]]-a[pos]+mmax[d[pos]]+a[c[pos][c[pos].size()-1]]);
		g[pos][1]=max(g[pos][1],g[f[pos]][1]-a[c[f[pos]][c[f[pos]].size()-1]]+a[pos]-mmin[d[pos]]+a[c[pos][c[pos].size()-1]]);
}else{
		g[pos][0]=-mmin[2];
		g[pos][1]=mmax[2];
}		
		dp[d[pos]][0]=max(dp[d[pos]][0],g[pos][0]);
		dp[d[pos]][1]=max(dp[d[pos]][1],g[pos][1]);
		F(i,0,c[pos].size()-1)q.push(c[pos][i]);
	}
}
int main() {
	F(iasdfdsaf,1,read()) {
		cin>>n;
		F(i,0,n)c[i].clear(),mmax[i]=-1e18,g[i][0]=g[i][1]=dp[i][0]=dp[i][1]=-1e18,mmin[i]=1e18;
		F(i,2,n) {
			read(f[i]);
			c[f[i]].push_back(i);
		}
		ans=0;
		dp[0][0]=dp[0][1]=0;
		F(i,2,n)read(a[i]);
		bfs();
		write(ans,'\n');
	}

	return 0;
}