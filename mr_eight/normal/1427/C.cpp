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
inline char readc(){
	register char c;
	while((c=getchar())==' '||c=='\n');
	return c;
}int dp[100002],n,r,t[100002],a[100002],b[100002],mmax[100002],ans;
int main(){memset(dp,-0x3f,sizeof(dp));dp[0]=0;
    cin>>r>>n;
    a[0]=b[0]=1;
    F(i,1,n){
    	t[i]=read(),a[i]=read(),b[i]=read();
    	if(i>=1000)dp[i]=mmax[i-1000]+1;
    	F(j,max(0,i-1000),i-1){
    		if(abs(a[i]-a[j])+abs(b[i]-b[j])+t[j]<=t[i])dp[i]=max(dp[i],dp[j]+1);
		}mmax[i]=max(mmax[i-1],dp[i]);
		ans=max(ans,dp[i]);
	}cout<<ans;
    return 0;
}