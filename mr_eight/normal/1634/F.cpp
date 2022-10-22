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
int a[300002],n,m,mod,f[300002],ans;
char s[5];
int main() {
	cin>>n>>m>>mod;
	f[1]=1%mod;
	F(i,2,n)f[i]=(f[i-1]+f[i-2])%mod;
	F(i,1,n)read(a[i]);
	F(i,1,n)a[i]=(a[i]+mod-read())%mod;
	UF(i,n,2)a[i]=(a[i]-a[i-1]+mod)%mod,a[i]=(a[i]-a[i-2]+mod)%mod;
	F(i,1,n)ans+=(a[i]!=0);
	F(i,1,m){
		scanf("%s",s);
		int l=read(),r=read();
		if(s[0]=='A'){
			ans-=(a[l]!=0);
			a[l]=(a[l]+1)%mod;
			ans+=(a[l]!=0);
			if(r!=n){
				ans-=(a[r+1]!=0);
				a[r+1]=(a[r+1]+mod-f[r-l+2])%mod;
				ans+=(a[r+1]!=0);
			}
			if(r<n-1){
				ans-=(a[r+2]!=0);
				a[r+2]=(a[r+2]+mod-f[r-l+1])%mod;
				ans+=(a[r+2]!=0);
			}
		}else{
			ans-=(a[l]!=0);
			a[l]=(a[l]+mod-1)%mod;
			ans+=(a[l]!=0);
			if(r!=n){
				ans-=(a[r+1]!=0);
				a[r+1]=(a[r+1]+f[r-l+2])%mod;
				ans+=(a[r+1]!=0);
			}
			if(r<n-1){
				ans-=(a[r+2]!=0);
				a[r+2]=(a[r+2]+f[r-l+1])%mod;
				ans+=(a[r+2]!=0);
			}
		}
		//F(j,1,n)cerr<<a[j]<<" ";
		puts(ans?"NO":"YES");
	}
	return 0;
}