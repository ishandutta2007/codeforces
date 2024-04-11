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
const int mod=998244353;
long long n,fac[1000002],ifac[1000002],inv[1000002];
inline long long pw(long long x,long long p){
    long long res=1;
    for(;p;p>>=1,x=x*x%mod)
        if(p&1)res=res*x%mod;
    return res;
}
inline long long getm(long long top,long long bot) {
	return (top*pw(bot,mod-2))%mod;
}
inline long long C(long long top,long long bot){
	if(top<bot||top<0||bot<0)return 0;
	return fac[top]*ifac[bot]%mod*ifac[top-bot]%mod;
}
vector<pair<int,pii> >g[200002];
vector<int>d[200002];int mmax[200002],fm[200002],fz[200002];
inline bool isp(int x){
	F(i,2,sqrt(x))if(x%i==0)return false;
	return true;
}
inline void addfm(int x){
	if(fz[x])--fz[x];
	else ++fm[x];
}
inline void addfz(int x){
	if(fm[x])--fm[x];
	else ++fz[x];
}
inline void mnsfm(int x){
	if(fm[x])--fm[x];
	else ++fz[x];
}
inline void mnsfz(int x){
	addfm(x);
}
inline void dfs(int pos,int fa){
	for(auto i:g[pos])if(i.first!=fa){
		for(auto j:d[i.second.first])addfz(j);
		for(auto j:d[i.second.second])addfm(j),mmax[j]=max(mmax[j],fm[j]);
		dfs(i.first,pos);
		for(auto j:d[i.second.first])addfm(j);
		for(auto j:d[i.second.second])addfz(j);
	}
}
int ans[200002];
inline void solve(int pos,int fa,ll now){
	ans[pos]=now;
	for(auto i:g[pos])if(i.first!=fa){
		solve(i.first,pos,now*i.second.first%mod*inv[i.second.second]%mod);
	}
}
int main() {
	n=200000;
	F(i,2,n)if(isp(i)){
		for(ll k=i;k<=n;k*=i)for(int j=k;j<=n;j+=k)d[j].push_back(i);
	}
	fac[0]=1;
	F(i,1,n)fac[i]=fac[i-1]*i%mod;
	ifac[n]=getm(1,fac[n]);
	UF(i,n-1,0)ifac[i]=ifac[i+1]*(i+1)%mod;
	F(i,1,n)inv[i]=ifac[i]*fac[i-1]%mod;
	F(adfs,1,read()){
		read(n);F(i,1,n)g[i].clear(),mmax[i]=fm[i]=fz[i]=0;
		F(i,2,n){
			int x=read(),y=read(),a=read(),b=read();
			g[x].push_back({y,{b,a}});
			g[y].push_back({x,{a,b}});
		}
		dfs(1,0);
		ll anss=1;
		F(i,1,n)anss=anss*pw(i,mmax[i])%mod;
		solve(1,0,anss);anss=0;F(i,1,n)anss+=ans[i];
		write(anss%mod);puts("");
	}
	return 0;
}