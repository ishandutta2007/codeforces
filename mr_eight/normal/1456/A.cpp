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
template<class T>
inline T read(T &x) {
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
inline int read(){
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
ll q[100002],l,r,t,n,p,k,x,y,dp[100002],ans;
char c[100002];
inline void push(int pos){
	r=0;
	q[++r]=pos;
}
int main(){
    cin>>t;
    while(t--){
    	memset(q,0,sizeof(q));
    	l=1,r=0;ans=LLONG_MAX;
    	memset(dp,0x3f,sizeof(dp));
    	cin>>n>>p>>k;
    	scanf("%s",c+1);
    	cin>>x>>y;
    	F(i,p,n){
    		if(c[i]=='1')dp[i]=(i-p)*y;
    		else dp[i]=(i-p)*y+x;
		}F(i,p+k,n){
			push(i-k);
			dp[i]=min(dp[i],dp[q[l]]+(i-k-q[l])*y+(c[i]=='0')*x);
		}F(i,n-k+1,n)ans=min(ans,dp[i]+max(0ll,(n-k+1-i)*y));
		cout<<ans<<'\n';
	}
    return 0;
}