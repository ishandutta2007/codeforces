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
//#pra gma G CC opti mize(3)
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
}int n;
ll a[300002],f[300002];
long long mod=998244353;
long long pow(long long x,long long p)
{
    long long res=1;
    for(;p;p>>=1,x=x*x%mod)
        if(p&1)res=res*x%mod;
    return res;
}
long long getm(long long top,long long bot) {
	return (top*pow(bot,mod-2))%mod;
}
long long C(ll n,ll m){
	return f[n]*getm(1,f[m])%mod*getm(1,f[n-m])%mod;
}
ll ans;
int main(){
    cin>>n;
    f[0]=1;
    F(i,1,300000)f[i]=f[i-1]*i%mod;
    F(i,1,2*n)a[i]=read();
    sort(a+1,a+2*n+1);
    F(i,1,n)ans-=a[i];
    F(i,n+1,n+n)ans+=a[i];
    cout<<ans%mod*C(n+n,n)%mod;
    return 0;
}