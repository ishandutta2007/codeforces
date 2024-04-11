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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define endl '\n'//
//#pragma GCC optimize(3)
using namespace std;
using std::bitset;
using namespace __gnu_pbds;
inline int read() {
	int x=0;
	bool fu=0;
	char ch=0;
	while(ch>'9'||ch<'0') {
		ch=getchar();
		if(ch=='-')fu=1;
	}
	while(ch<='9'&&ch>='0') x=(x*10+ch-48),ch=getchar();
	return fu?-x:x;
}ll T,n,a[100002],k,z,dp[100002][7][2],ans;
inline int findpos(int r,int l){
	return r-l+1;
}
int main(){
    cin>>T;
    while(T--){
    	cin>>n;
    	F(i,0,k+1)F(j,0,6)dp[i][j][0]=dp[i][j][1]=-INT_MAX;
    	dp[0][0][0]=0;
    	cin>>k>>z;
    	F(i,1,n){
    		a[i]=read();
		}F(i,1,k){
			F(j,0,z){
				ri pos=findpos(i,j);
				if(pos<=0||pos>n)continue;
				dp[i][j][0]=max(dp[i-1][j][0]+a[pos],dp[i-1][j][1]+a[pos]);
				if(j!=0)dp[i][j][1]=dp[i][j-1][0]+a[pos];
			}
		}
		ans=-INT_MAX;
		F(i,k-z,k){
			ri j=k-i;
			ans=max(ans,max(dp[i][j][1],dp[i][j][0]));
		}cout<<ans+a[1]<<endl;
	}
    return 0;
}