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
}
inline char readc(){
	register char c;
	while((c=getchar())==' '||c=='\n');
	return c;
}string n;ll  now,ans;
ll qwq[100002],d[100002],dp[100002];
int main(){
    cin>>n;
    F(i,0,n.size()-1){
    	now*=10;
    	now+=n[i]-'0';
    	now%=mod;
    	d[i]=now;
	}//ans=now*(n.size()*(n.size()-1)/2%mod)%mod;
	qwq[0]=1;
	F(i,1,100000){
		qwq[i]=qwq[i-1]*10%mod;
	}
	F(i,0,n.size()-1){
		if(i>0){
			dp[i]+=d[i-1];
		dp[i]+=dp[i-1];
		dp[i]%=mod;
		}
	}
	F(i,0,n.size()-1){
		ans+=(dp[i]*qwq[n.size()-i-1]%mod+(now-d[i]*qwq[n.size()-i-1]%mod+mod+mod)*(i+1)%mod);
	}cout<<(ans+mod*mod)%mod;
    return 0;
}