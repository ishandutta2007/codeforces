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
namespace fastIO {
	template<class T>
	inline void read(T &x) {
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
	char _n_u_m_[40];
	template<class T>
	inline void write(T x ) {
		if(x==0){
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		register int cnt = 0 ;
		while( tmp > 0 ) {
			_n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
	}
	template<class T>
	inline void write(T x ,char ch) {
		write(x);
		putchar(ch);
	}
}
using namespace fastIO;
const int MAXN=100002;
int n,t1,t2,f[MAXN],a[MAXN];ll dp[MAXN][5];
vector<int>g[MAXN],c[MAXN];
bool vis[MAXN];
inline void make_tree(int pos){
	vis[pos]=1;ri nxt;
	F(i,0,g[pos].size()-1){
		nxt=g[pos][i];
		if(!vis[nxt]){
			f[nxt]=pos;
			c[pos].push_back(nxt);
			make_tree(nxt);
		}
	}
}
inline void dfs(int pos){
	dp[pos][1]=dp[pos][3]=a[pos];ll temp=0;
	for(auto i:c[pos]){
		dfs(i);
		dp[pos][4]=max(dp[pos][4],dp[i][4]);
		dp[pos][4]=max(dp[pos][4],dp[pos][3]+dp[i][3]);
		dp[pos][4]=max(dp[pos][4],dp[pos][2]+dp[i][1]);
		dp[pos][4]=max(dp[pos][4],dp[pos][1]+dp[i][2]);
		dp[pos][3]=max(dp[pos][3],dp[i][3]);
		dp[pos][3]=max(dp[pos][3],dp[pos][1]+dp[i][1]);
		dp[pos][2]=max(dp[pos][2],temp+a[pos]+dp[i][1]);
		dp[pos][2]=max(dp[pos][2],dp[i][2]+a[pos]);
		dp[pos][2]=max(dp[pos][2],dp[pos][1]+dp[i][3]);
		dp[pos][1]=max(dp[pos][1],a[pos]+dp[i][1]);
		temp=max(temp,dp[i][3]);
	}
}
int main(){
    cin>>n;
    F(i,1,n)read(a[i]);
    F(i,2,n){
    	t1=read(),t2=read();
    	g[t1].push_back(t2);
    	g[t2].push_back(t1);
	}make_tree(1);
	dfs(1);
	cout<<dp[1][4];
    return 0;
}