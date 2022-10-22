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
}int n,m,t,t1,t2,dp[500002],f[500002],n2,temp[1000002];
bool vis[500002];
vector<int>g[500002];
inline void dfs(int pos,int fa){
	f[pos]=fa;
	dp[pos]=dp[fa]+1;
	vis[pos]=1;
	F(i,0,g[pos].size()-1){
		if(!vis[g[pos][i]]){
			dfs(g[pos][i],pos);
		}
	}
}
inline bool cmp(int x,int y){
	return dp[x]<dp[y];
}
inline void solve(){
	F(i,1,n){
		if(dp[i]>=n2){
			printf("PATH\n%d\n",dp[i]);
			while(i){
				printf("%d ",i);
				i=f[i];
			}printf("\n");
			return;
		}
	}printf("PAIRING\n%d\n",(n2+1)/2);
	F(i,1,n){
		temp[i]=i;
	}sort(temp+1,temp+n+1,cmp);
	ri i=2;
	
	while(n2>0){
		
		if(dp[temp[i]]==dp[temp[i-1]]){
			n2-=2;
			printf("%d %d\n",temp[i],temp[i-1]);
			i+=2;
		}else i++;
	}
}
int main(){
    cin>>t;
    while(t--){
    	n=read(),m=read();
    	n2=(n+1)/2;
    	F(i,1,n)dp[i]=f[i]=0,g[i].clear(),vis[i]=0;
    	F(i,1,m){
    		t1=read(),t2=read();
    		g[t1].push_back(t2);
    		g[t2].push_back(t1);
		}dfs(1,0);
		solve();
	}
    return 0;
}