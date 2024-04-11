//#include <bits/c++config.h>
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
#define ll long long //long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
#define cp complex<double>
#define endl '\n'//
//#pragma GCC optimize(3)
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
long long mod=1000000007,dd[1000002],dp[1000002];
long long pow(long long x,long long p)
{
    long long res=1;
    for(;p;p>>=1,x=x*x%mod)
        if(p&1)res=res*x%mod;
    return res;
}
long long getm(long long top,long long bot) {
	return (top*pow(bot,mod-2))%mod;
}int n;
long long C(ll u,ll d){
	return getm(dd[d],dd[u]*dd[d-u]%mod);
}
long long ans;
int main(){dd[0]=1;
	F(i,1,1000000)dd[i]=dd[i-1]*i%mod;
    cin>>n;
    dp[1]=0;
    F(i,2,n){
    	dp[i]=(i-2)*dd[i-1];
    	dp[i]+=2*dp[i-1];
    	dp[i]%=mod;
	}cout<<dp[n];
    return 0;
}