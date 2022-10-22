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
}ll t,n,dp[4][4][200002],ans;
char c;
string s;
bool a[200002];
inline bool check(int num){
	bool a=(num&8),b=(num&4),c=(num&2),d=(num&1);
	if(a==1&&c==1&&b==1)return 0;
	if(a==0&&b==0&&c==0)return 0;
	if(d==1&&c==1&&b==1)return 0;
	if(d==0&&b==0&&c==0)return 0;
	return 1;
}
int main(){
    cin>>t;
    while(t--){
    	cin>>n>>s;
    	ans=INT_MAX;
    	F(i,1,n){
    		if(s[i-1]=='L')a[i]=0;
    		else a[i]=1;
		}F(i,0,n){
			F(j,0,3){
				F(k,0,3){
					dp[j][k][i]=INT_MAX;
				}
			}
		}dp[a[1]*2+a[2]][a[1]*2+a[2]][2]=0;
		dp[a[1]*2+(!a[2])][a[1]*2+(!a[2])][2]=1;
		dp[(!a[1])*2+a[2]][(!a[1])*2+a[2]][2]=1;
		dp[(!a[1])*2+(!a[2])][(!a[1])*2+(!a[2])][2]=2;
		F(i,3,n){
			F(j,0,3){
				F(tp,0,3){
					if(j==3){
						dp[tp][j][i]=min(dp[tp][j][i],dp[tp][1][i-1]);
					}else if(j==2){
						dp[tp][j][i]=min(dp[tp][3][i-1],dp[tp][1][i-1]);
					}else if(j==1){
						dp[tp][j][i]=min(dp[tp][0][i-1],dp[tp][2][i-1]);
					}else{
						dp[tp][j][i]=min(dp[tp][j][i],dp[tp][2][i-1]);
					}dp[tp][j][i]+=(a[i]!=(j&1));
				}
			}
		}F(i,0,15){
			if(check(i)){
				ans=min(ans,dp[i%4][i/4][n]);
			}
		}cout<<ans<<endl;
	}
    return 0;
}