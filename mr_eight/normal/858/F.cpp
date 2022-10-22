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
int n,m,t1,t2,d[200002];
bool vis[200002];
vector<int>g[200002],c[200002],orz[200002];
struct S{
	int a,b,c;
};
vector<S>ans;
inline void dfs(int pos,int dd,int fa){
	d[pos]=dd;vis[pos]=true;
	for(int i:g[pos]){
		if(i==fa)continue;
		if(!vis[i])dfs(i,dd+1,pos),c[pos].push_back(i);
		else if(dd>d[i])orz[i].push_back(pos);
	}
}
inline bool getans(int pos){
	vector<int> &qwq=orz[pos];
	for(int i:c[pos]){
		if(!getans(i))qwq.push_back(i);
		else ans.push_back({pos,i,orz[i][0]});
	}
	while(qwq.size()>=2){
		ans.push_back({qwq.back(),pos,qwq[qwq.size()-2]});
		qwq.pop_back();qwq.pop_back();
	}
	return qwq.size();
}
int main() {
	cin>>n>>m;
	F(i,1,m){
		read(t1,t2);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	F(i,1,n)if(!vis[i])
	dfs(i,0,0),
	getans(i);
	write(ans.size(),'\n');
	for(auto i:ans)write(i.a,' '),write(i.b,' '),write(i.c,'\n');
	return 0;
}