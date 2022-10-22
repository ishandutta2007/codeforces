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
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
#define cp complex<double>
#define mod 1000000007ll
#pragma GCC optimize(3)
using namespace std;
using std::bitset;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
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
inline char readc() {
	register char c;
	while((c=getchar())==' '||c=='\n');
	return c;
}
int n,pw[22],dp[1000002][22][2],now,temp,ans;
int main() {
	cin>>n;
	if(n==1) {
		cout<<1;
		return 0;
	}
	pw[0]=1;
	F(i,1,20)pw[i]=2*pw[i-1];
	temp=1,now=0;
	while(temp<=n) {
		temp*=2,now++;
	}
	temp>>=1,now--;
	if(temp/2*3<=n) {
		dp[1][now-1][1]=1;
		F(i,1,n-1) {
			F(j,0,now-1) {
				F(k,0,1) {
					dp[i+1][j][k]+=1ll*dp[i][j][k]*(n/(pw[j]*(1+2*k))-i)%mod;
					dp[i+1][j][k]%=mod;
					if(j)dp[i+1][j-1][k]+=1ll*dp[i][j][k]*(n/(pw[j-1]*(1+2*k))-n/(pw[j]*(1+2*k)))%mod,dp[i+1][j-1][k]%=mod;
					if(k) {
						dp[i+1][j][0]+=1ll*dp[i][j][k]*((n/pw[j])-n/(pw[j]*3))%mod;
						dp[i+1][j][0]%=mod;
					}
				}
			}
		}
		ans+=dp[n][0][0];
		memset(dp,0,sizeof(dp));
	}
	dp[1][now][0]=1;
	F(i,1,n-1) {
		F(j,0,now) {
			#define k 0
				dp[i+1][j][k]+=1ll*dp[i][j][k]*(n/(pw[j]*(1+2*k))-i)%mod;
				dp[i+1][j][k]%=mod;
				if(j)dp[i+1][j-1][k]+=1ll*dp[i][j][k]*(n/(pw[j-1]*(1+2*k))-n/(pw[j]*(1+2*k)))%mod,dp[i+1][j-1][k]%=mod;
			
		}
	}
	ans+=dp[n][0][0];
	cout<<ans%mod;
	return 0;
}