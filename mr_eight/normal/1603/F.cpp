//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
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
#include <random>
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
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
using namespace std;
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
	inline void write(T x) {
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
inline long long pw(long long x,long long p){
    long long res=1;
    for(;p;p>>=1,x=x*x%mod)
        if(p&1)res=res*x%mod;
    return res;
}
ll pre[10000002],pw2n[10000002],pw2[10000002],n,k,x;
int main() {
	pw2[0]=1;
	F(i,1,10000000)pw2[i]=(pw2[i-1]<<1)%mod;
	F(iakioi,1,read()){
		read(n);read(k);read(x);
		if(x==0){
			if(n>k){
				puts("0");
			}else{
				ll ans=1;
				F(i,0,n-1){
					ans=ans*(pw2[k]-pw2[i]+mod)%mod;
				}
				write(ans,'\n');
			}	
		}else{
			pre[0]=pw2n[0]=1;
			pw2n[1]=pw(2,n);
			F(i,2,k)pw2n[i]=pw2n[i-1]*pw2n[1]%mod;
			F(i,1,k)pre[i]=pre[i-1]*(pw2[k-i]-1)%mod;
			ll ans=0;
			F(i,0,k-1){
				if(i&1){
					ans-=pw2[k-i-1]*pre[i]%mod*pw2n[k-i-1]%mod;
				}else{
					ans+=pw2[k-i-1]*pre[i]%mod*pw2n[k-i-1]%mod;
				}
			}
			write((ans%mod+mod)%mod,'\n');
		}
	}
	return 0;
}