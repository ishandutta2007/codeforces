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
#define mod 998244353
#define i2 499122177
#define NOW now
const int MAXN=302;
int n,t1,t2,f[MAXN],now,dp[MAXN][MAXN],nxt[MAXN],dp2[MAXN][MAXN],nxt2[MAXN],sz[MAXN];
vector<int>g[MAXN],c[MAXN];
bool vis[MAXN];
ll ans;
inline void make_tree(int pos){
	vis[pos]=sz[pos]=1;ri nxt;
	F(i,0,g[pos].size()-1){
		nxt=g[pos][i];
		if(!vis[nxt]){
			f[nxt]=pos;
			c[pos].push_back(nxt);
			make_tree(nxt);
			sz[pos]+=sz[nxt];
		}
	}
}
inline void dfs(int pos){
	dp[pos][0]=dp2[pos][0]=i2;
	ri ns=0;
	F(i,0,c[pos].size()-1){
		dfs(c[pos][i]);
		memset(nxt,0,sizeof(nxt));
		memset(nxt2,0,sizeof(nxt2));
		ri ch=c[pos][i];
		F(i,0,ns){
			F(j,0,sz[ch]){
				nxt[max(i,j+1)]=(nxt[max(i,j+1)]+1ll*dp[pos][i]*dp[ch][j])%mod;
				if(now-j-1>=i)nxt2[j+1]=(nxt2[j+1]+1ll*dp[pos][i]*dp2[ch][j])%mod;
				else nxt[i]=(nxt[i]+1ll*dp[pos][i]*dp2[ch][j])%mod;
				if(now-i>=j+1)nxt2[i]=(nxt2[i]+1ll*dp2[pos][i]*dp[ch][j])%mod;
				else nxt[j+1]=(nxt[j+1]+1ll*dp2[pos][i]*dp[ch][j])%mod;
				nxt2[min(i,j+1)]=(nxt2[min(i,j+1)]+1ll*dp2[pos][i]*dp2[ch][j])%mod;
			}
		}ns+=sz[ch];
		F(ii,0,ns)dp[pos][ii]=nxt[ii],dp2[pos][ii]=nxt2[ii];
	}
}
int main(){
    cin>>n;
    F(i,2,n){
    	t1=read(),t2=read();
    	g[t1].push_back(t2);
    	g[t2].push_back(t1);
	}make_tree(1);
	ans=n;
	UF(i,n,0){
		now=i;
		memset(dp,0,sizeof(dp));
		dfs(1);
		F(j,0,n)ans+=mod-dp2[1][j];
	}write(ans%mod);
    return 0;
}