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
//#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
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
const long long mod=998244353;
inline long long pw(long long x,long long p){
    long long res=1;
    for(;p;p>>=1,x=x*x%mod)
        if(p&1)res=res*x%mod;
    return res;
}
inline long long getm(long long top,long long bot) {
	return (top*pw(bot,mod-2))%mod;
}
long long fac[1000002],ifac[1000002],inv[1000002];
int n,a[1000002],g,cnt[1000002],tot,v[1000002],w[1000002],num;
ll ans=0,sum=0;
inline ll calc(int len,int ww){
	int nlen=n/len;ll w=fac[len];
	F(i,1,num)v[i]=cnt[i]/nlen,w=w*ifac[v[i]]%mod;
	sum+=w*ww%mod;ll rt=0;w=w*inv[len]%mod*inv[len-1]%mod;
	F(i,1,num)if(v[i]>=2)rt+=w*v[i]%mod*(v[i]-1)%mod;//if(len!=n)cerr<<rt<<"K"<<w<<endl;
	return rt%mod;
}
int main() {
	n=1e6;fac[0]=1;
	F(i,1,n)fac[i]=fac[i-1]*i%mod;
	ifac[n]=getm(1,fac[n]);
	UF(i,n-1,0)ifac[i]=ifac[i+1]*(i+1)%mod;
	F(i,1,n)inv[i]=ifac[i]*fac[i-1]%mod;
	F(iakioi,1,read()){
		read(n);F(i,1,n)cnt[i]=w[i]=0;ans=sum=0;
		F(i,1,n)read(a[i]),++cnt[a[i]],++w[__gcd(i,n)];cnt[n+1]=0;
		sort(cnt+1,cnt+n+1);reverse(cnt+1,cnt+n+1);
		F(i,1,n+1)if(!cnt[i]){
			num=i-1;
			break;
		}
		if(*max_element(cnt+1,cnt+n+1)==n){
			write(1,'\n');
			continue;
		}
		g=n;
		F(i,1,n)g=__gcd(g,cnt[i]);tot=0;
		F(i,1,g)if(g%i==0){
			ans+=1ll*w[n/i]*calc(n/i,w[n/i])%mod;
			++tot;
		}
		//cerr<<ans%mod*n%mod*sum%mod<<endl;
		write((n+mod-getm(ans%mod*n%mod,sum%mod))%mod,'\n');
	}
	return 0;
}