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
#define mod 1000000007
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
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
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
ll n,a[302],C[502][502],x[302],num[302],cnt,dp[302][302],orz,pw[502][502],ans;
int main() {
	F(i,0,500)C[i][0]=pw[i][0]=1;
	F(i,1,500){
		F(j,1,500){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
			pw[i][j]=pw[i][j-1]*i%mod;
		}
	}
	cin>>n;
	F(i,1,n){
		read(a[i]);
		F(j,1,cnt){
			orz=sqrt(x[j]*a[i]);
			if(orz*orz==x[j]*a[i]){
				num[j]++;
				goto ak;
			}
		}
		x[++cnt]=a[i];
		num[cnt]=1;
		ak:;
	}
	dp[1][num[1]-1]=1;
	ll sum=num[1];
	ans=1;
	F(i,1,n){
		F(j,2,num[i])ans=ans*j%mod;
	}
	F(i,2,cnt){
		F(j,0,sum){
			F(k,0,min(j,(int)num[i])){
				F(l,0,min(num[i]-k,sum-j+1)){
		dp[i][j-k+num[i]-k-l]=(dp[i][j-k+num[i]-k-l]+dp[i-1][j]*C[j][k]%mod*C[sum-j+1][l]%mod*C[num[i]-1][k+l-1])%mod;
				}
			}
		}
		sum+=num[i];
	}
	cout<<ans*dp[cnt][0]%mod;
	return 0;
}