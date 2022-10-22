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
vector<int>g[600002];bool vis[600002],vis2[600002];int now=0,n,ans[600002];
inline void dfs(ri pos){vis[pos]=1;now++;
	F(i,0,g[pos].size()-1){
		if(!vis[g[pos][i]])dfs(g[pos][i]);
	}
}inline void bfs(ri pos){vis2[pos]=1;ans[pos]=now;
	F(i,0,g[pos].size()-1){
		if(!vis2[g[pos][i]])bfs(g[pos][i]);
	}
}
int main() {
F(qwq,1,read()){
	cin>>n;string sss;
	getline(cin,sss);
	F(i,0,2*n+1)g[i].clear(),vis[i]=vis2[i]=0;
	F(i,1,n){
		if(getchar()=='L'){
			g[i].push_back(i-1+n+1);
			g[i-1+n+1].push_back(i);
		}else{
			g[i-1].push_back(i+n+1);
			g[i+n+1].push_back(i-1);
		}
	}F(i,0,n+n+1){
		if(!vis[i])now=0,dfs(i),bfs(i);
	}F(i,0,n)write(ans[i],' ');puts("");
}
	return 0;
}