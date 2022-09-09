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
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
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
int n,m,p[300002],cnt[300002];
int a[300002],f[300002],ccnt;
vector<int>vec;
bool vis[300002];
inline void dfs(int pos){
	if(!vis[pos]){
		vis[pos]=1;
		dfs(f[pos]);
	}
}
inline void check(int x){
	F(i,1,x)a[i]=n-x+i;
	F(i,x+1,n)a[i]=i-x;
	F(i,1,n)f[a[i]]=p[i],vis[i]=0;
	int ans=0;
	F(i,1,n)if(!vis[i])dfs(i),--ans;
	if(n+ans<=m)vec.push_back(x),++ccnt;
}
int main() {
	F(iasdf,1,read()){
		read(n);read(m);ccnt=0;
		F(i,1,n)read(p[i]);
		F(i,0,n)cnt[i]=0;
		F(i,1,n)++cnt[(i-p[i]+n)%n];
		F(i,0,n-1)if(cnt[i]>=(n+2)/3){
			check(i);
		}
		write(ccnt,' ');
		for(auto i:vec)write(i,' ');puts("");vec.clear();
	}
	return 0;
}