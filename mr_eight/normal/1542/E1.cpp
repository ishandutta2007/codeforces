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
int dp[502][502*502/2],pre[502][502*502/2],n,mod,C[502][502],orz[502*502/2],sto[502*502/2],tot[114514],fac[114514];
int main() {cin>>n>>mod;fac[0]=1;
	F(i,0,500)C[i][0]=1%mod;F(i,1,500)fac[i]=1ll*fac[i-1]*i%mod;
	F(i,1,n)F(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	
	dp[0][0]=1%mod;
	pre[0][0]=1%mod;
	F(i,1,n){
		F(j,0,i*(i-1)/2){
			if(i<=j)dp[i][j]=(pre[i-1][min(j,(i-1)*(i-2)/2)]-pre[i-1][j-i]+mod)%mod;
			else dp[i][j]=pre[i-1][min(j,(i-1)*(i-2)/2)];
			pre[i][j]=(pre[i][j-1]+dp[i][j])%mod;
		}
	}
	ll ans=0;
	F(i,3,n-1){
		ll temp=0;
		orz[0]=dp[i][0];
		F(j,1,i*(i-1)/2)orz[j]=(orz[j-1]+pre[i][j])%mod,sto[j]=(sto[j-1]+1ll*pre[i][j]*j)%mod;
		F(j,2,i*(i-1)/2){
			if(j>i+1)temp+=1ll*(sto[j-2]-sto[j-i-2]-1ll*(orz[j-2]-orz[j-i-2])*(j-i-2))%mod*dp[i][j]%mod;
			else temp+=1ll*(sto[j-2]-1ll*(orz[j-2])*(j-i-2))%mod*dp[i][j]%mod;
			tot[j]+=temp;
		}temp%=mod;//cerr<<temp<<endl;
		ans+=1ll*C[n][i+1]*fac[n-i-1]%mod*temp%mod;
	}
	cout<<(ans%mod+mod)%mod;
//	F(i,0,15)cerr<<endl<<tot[i];
	return 0;
}