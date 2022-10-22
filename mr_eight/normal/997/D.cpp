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
#define mod 998244353 
long long fac[10002],ifac[10002],qwq[40],qaq[40],ans;
int n,k;
inline long long pw(long long x,long long p) {
	long long res=1;
	for(; p; p>>=1,x=x*x%mod)
		if(p&1)res=res*x%mod;
	return res;
}
inline long long getm(long long top,long long bot) {
	return (top*pw(bot,mod-2))%mod;
}
inline long long C(long long top,long long bot) {
	if(top<bot||top<0||bot<0)return 0;
	return fac[top]*ifac[bot]%mod*ifac[top-bot]%mod;
}
struct T{
	int n,t1,t2,dp[4002][40],f[4002][40],g[4002][40],sum[4002][40];
	vector<int>G[4002];
	inline void dfs1(int pos,int lst){
		f[pos][0]=1;
		for(int i:G[pos])if(i!=lst){
			dfs1(i,pos);
			F(j,0,k)sum[pos][j]=(sum[pos][j]+f[i][j])%mod;
		}
		F(x,1,k){
			for(int i:G[pos])if(i!=lst){
				F(y,1,x){
					f[pos][x]=(f[pos][x]+1ll*f[pos][x-y]*f[i][y-1])%mod;
				}
			}
		}
	}
	inline void dfs2(int pos,int lst){
		if(pos!=1){
			g[pos][1]=1;
			F(x,2,k){
				F(y,1,x-1){
					g[pos][x]=(g[pos][x]+1ll*g[pos][x-y]*(g[lst][y]+(ll)(sum[lst][y-1]-f[pos][y-1]+mod)))%mod;
				}
			}
		}
		dp[pos][0]=1;
		F(i,1,k){
			F(j,1,i){
				dp[pos][i]=(dp[pos][i]+1ll*dp[pos][i-j]*(sum[pos][j-1]+g[pos][j]))%mod;
			}
		}
		for(int i:G[pos])if(i!=lst)dfs2(i,pos);
	}
	void main(){
		F(i,2,n){
			read(t1);read(t2);
			G[t1].push_back(t2);
			G[t2].push_back(t1);
		}
		dfs1(1,0);
		dfs2(1,0);
	}
}A,B;
int main() {
	n=10000;
	fac[0]=1;
	F(i,1,n)fac[i]=fac[i-1]*i%mod;
	ifac[n]=getm(1,fac[n]);
	UF(i,n-1,0)ifac[i]=ifac[i+1]*(i+1)%mod;
	cin>>A.n>>B.n>>k;
	if(k&1){
		puts("0");
		return 0;
	}
	k>>=1;
	A.main();
	B.main();
	F(i,0,k){
		F(j,1,A.n)qwq[i]+=A.dp[j][i];
		F(j,1,B.n)qaq[i]+=B.dp[j][i];
		qwq[i]%=mod,qaq[i]%=mod;
	}
	F(i,0,k)ans+=C(k<<1,i<<1)*qwq[i]%mod*qaq[k-i]%mod;
	cout<<ans%mod;
	return 0;
}