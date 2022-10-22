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
const long long mod=998244353;
il long long pw(long long x,long long p)
{
    long long res=1;
    for(;p;p>>=1,x=x*x%mod)
        if(p&1)res=res*x%mod;
    return res;
}
il long long getm(long long top,long long bot) {
	return (top*pw(bot,mod-2))%mod;
}
int n;
ll p[200002],ans,sum[200002];
set<int>s;
inline ll cnt(ri l,ri r){
	return getm(sum[l]-sum[r+1]+mod,p[r+1]);
}
int main() {
	cin>>n;ri QwQ=read();
	F(i,1,n)p[i]=getm(100,read());sum[n]=p[n];
	UF(i,n-1,1)p[i]=p[i]*p[i+1]%mod,sum[i]=(p[i]+sum[i+1])%mod;
	p[n+1]=1;
	s.insert(n+1);s.insert(1);
	ans=cnt(1,n);
	ri pos;
	while(QwQ--){
		read(pos);
		if(s.count(pos)){
			ri lst,nxt;
			auto l=s.upper_bound(pos);
			nxt=*l;
			s.erase(pos);
			--l;
			lst=*l;
			ans-=cnt(lst,pos-1);
			ans-=cnt(pos,nxt-1);
			ans+=cnt(lst,nxt-1);
		}else{
			ri lst,nxt;
			auto l=s.upper_bound(pos);
			nxt=*l;
			--l;
			lst=*l;
			s.insert(pos);
			ans+=cnt(lst,pos-1);
			ans+=cnt(pos,nxt-1);
			ans-=cnt(lst,nxt-1);
		}ans%=mod;
		if(ans<0)ans+=mod;
		write(ans,'\n');
	}
	return 0;
}