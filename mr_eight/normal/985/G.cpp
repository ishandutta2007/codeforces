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
#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define itn int
#define nit int
#define ull unsigned long long
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
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
	}
	char _n_u_m_[40];
	template<class T>
	inline void write(T x ) {
		if(x==0) {
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
int n,m,x[200002],y[200002];
vector<int>g[200002],G[200002];
bitset<200002>vis;
ull a,b,c,ans;
inline ull bi(int n) {
	return 1ull*n*(n-1)/2;
}
inline ull sum(int l,int r) {
	return (1ull*r*(r+1)-1ull*l*(l-1))/2;
}
inline ull query(int i,int j,int k){
	int x=min(min(i,j),k),z=max(max(i,j),k),y=x^z^i^j^k;
	return a*x+b*y+c*z;
}
int main() {
	cin>>n>>m>>a>>b>>c;
	F(i,1,m) {
		read(x[i],y[i]);
		if(x[i]>y[i])swap(x[i],y[i]);
		g[x[i]].push_back(y[i]);
		g[y[i]].push_back(x[i]);
	}
	F(i,1,m) {
		if(g[x[i]].size()<g[y[i]].size())G[x[i]].push_back(y[i]);
		else G[y[i]].push_back(x[i]);
	}
	F(i,0,n-1) {
		ans+=a*i*bi(n-i-1)+b*i*i*(n-i-1)+c*i*bi(i);
	}
	F(i,1,m) {
		ans-=x[i]*(a*(n-x[i]-2)+b*x[i])+y[i]*(c*(y[i]-1)+b*(n-y[i]-1));
		ans-=a*sum(0,x[i]-1)+b*sum(x[i]+1,y[i]-1)+c*sum(y[i]+1,n-1);
	}
	F(i,0,n-1) {
		sort(g[i].begin(),g[i].end());
		int pos=lower_bound(g[i].begin(),g[i].end(),i)-g[i].begin();
		ans+=a*i*bi(g[i].size()-pos)+b*i*pos*(g[i].size()-pos)+c*i*bi(pos);
		F(j,0,pos-1)ans+=a*g[i][j]*(g[i].size()-j-1)+b*g[i][j]*j;
		F(j,pos,g[i].size()-1)ans+=b*g[i][j]*(g[i].size()-j-1)+c*g[i][j]*j;
	}
	F(i,0,n-1) {
		for(int j:G[i])vis[j]=true;
		for(int j:G[i])for(int k:G[j])if(vis[k]) {
			ans-=query(i,j,k);
		}
		for(int j:G[i])vis[j]=false;
	}
	cout<<ans;
	return 0;
}
/*
3 3
11 45 14
0 1
1 2
*/