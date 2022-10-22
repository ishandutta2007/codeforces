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
}ll A,B,C,a[2002],b[2002],c[2002],ans,dp[203][203][203];
inline int tot(){
	ri rt=0;
	if(A)rt++;
	if(B)rt++;
	if(C)rt++;
	return rt;
}
int main(){
    cin>>A>>B>>C;
    F(i,1,A)a[i]=read();
    F(i,1,B)b[i]=read();
    F(i,1,C)c[i]=read();
    sort(a+1,a+A+1);
    sort(b+1,b+B+1);
    sort(c+1,c+C+1);
    UF(i,A+1,1){
    	UF(j,B+1,1){
    		UF(k,C+1,1){
    			dp[i][j][k]=max(max(dp[i+1][j][k],dp[i][j+1][k]),dp[i][j][k+1]);
    			dp[i][j][k]=max(dp[i][j][k],dp[i][j+1][k+1]+c[k]*b[j]);
    			dp[i][j][k]=max(dp[i][j][k],dp[i+1][j+1][k]+a[i]*b[j]);
    			dp[i][j][k]=max(dp[i][j][k],dp[i+1][j][k+1]+a[i]*c[k]);
			}
		}
	}cout<<dp[1][1][1];
    return 0;
}