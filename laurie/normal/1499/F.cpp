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
#pragma GCC optimize(2)
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
#define mod 998244353
const int MAXN=5002;
int n,t1,t2,f[MAXN],k,cnt,sz[MAXN],pw[MAXN],temp[MAXN];
vector<int>g[MAXN],c[MAXN];
bool vis[MAXN];
unsigned int dp[MAXN][MAXN],tot[MAXN][MAXN];
inline void make_tree(int pos) {
	vis[pos]=sz[pos]=1;
	ri nxt;
	F(i,0,g[pos].size()-1) {
		nxt=g[pos][i];
		if(!vis[nxt]) {
			f[nxt]=pos;
			c[pos].push_back(nxt);
			make_tree(nxt);sz[pos]+=sz[nxt];
		}
	}
}
inline void dfs(ri pos) {
	F(i,0,c[pos].size()-1) {
		dfs(c[pos][i]);
	}
	tot[0][0]=1;
	cnt=c[pos].size();
	F(i,0,cnt-1)temp[i]=c[pos][i];
	F(j,0,cnt-1)tot[j+1][0]=1ll*tot[j][0]*dp[temp[j]][k]%mod;
	F(i,1,k) {
		tot[0][i]=1;
		F(j,0,cnt-1) {
			tot[j+1][i]=1ll*tot[j][i]*(dp[temp[j]][i-1]+dp[temp[j]][k])%mod;
		}
	}dp[pos][0]=tot[cnt][0];
	F(j,1,k) {
		dp[pos][j]=dp[pos][j-1];
		ll ak=1;
		UF(i,cnt-1,0) {
			if(j>1)dp[pos][j]=(dp[pos][j]+1ll*(dp[temp[i]][j-1]-dp[temp[i]][j-2]+mod)%mod*tot[i][min(k-j,j-1)]%mod*ak)%mod;
			else dp[pos][j]=(dp[pos][j]+1ll*dp[temp[i]][j-1]%mod*tot[i][min(k-j,j-1)]%mod*ak)%mod;
			if(j!=k)ak*=(dp[temp[i]][min(k-j-1,j-1)]+dp[temp[i]][k]);
			else ak*=(dp[temp[i]][k]);
			ak%=mod;
		}
	}
}
int main() {
//	freopen("data.txt","r",stdin);
	cin>>n>>k;
	F(i,2,n) {
		t1=read(),t2=read();
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	make_tree(1);
	dfs(1);
	write(dp[1][k]);
	return 0;
}