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
}ll n,a[200002],f[200002],root[200002],isrt[200002],num,ans,dp[200002];
vector<int>c[200002];
void go(int pos){dp[pos]=a[pos];
	F(i,0,c[pos].size()-1){
		go(c[pos][i]);
		if(dp[c[pos][i]]>0){
			dp[pos]+=dp[c[pos][i]];
		}
	}
}void dfs(int pos){
	F(i,0,c[pos].size()-1){
		if(dp[c[pos][i]]>0){
			dfs(c[pos][i]);
		}
	}cout<<pos<<' ';
	F(i,0,c[pos].size()-1){
		if(dp[c[pos][i]]<=0){
			dfs(c[pos][i]);
		}
	}
}
int main(){
    cin>>n;
    F(i,1,n){
    	a[i]=read();
	}F(i,1,n){
		f[i]=read();
		if(f[i]==-1){
			root[++num]=i;
			isrt[i]=1;
		}else{
			c[f[i]].push_back(i);
		}
	}F(i,1,n){
		if(isrt[i])go(i);
	}
	F(i,1,n){
		ans+=dp[i];
	}cout<<ans<<endl;
	F(i,1,n){
		if(isrt[i])dfs(i);
	}
    return 0;
}