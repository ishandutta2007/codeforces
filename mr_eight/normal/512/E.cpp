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
int n,ed[1002][1002],cnt,cntt;
pii ans[114514],anss[114514];
bool tar;
inline int orz(int x){
	return x?(x>n?x-n:x):n;
}
inline void rev(int x,int y){
	int z=1,w;
	if(y-x==2)w=x+1;
	else if(ed[x+1][y])w=x+1;
	else if(ed[x][y-1])w=y-1;
	else
	F(i,x+2,y-2){
		if(ed[x][i]&&ed[y][i])w=i;
	} 
	if(tar)anss[++cntt]=make_pair(z,w);
	else ans[++cnt]=make_pair(x,y);
	ed[z][w]=ed[w][z]=ed[x][y];
	ed[x][y]=ed[y][x]=0;
}
inline void solve(){
	F(i,3,n-1)while(!ed[1][i]){
		int x=2,y=n;
		F(j,3,i-1)if(ed[1][j])x=j;
		UF(j,n-1,i+1)if(ed[1][j])y=j;
		rev(x,y);
	}
}
int main() {
	cin>>n;
	F(i,1,n-3){
		ri t1=read(),t2=read();
		ed[t1][t2]=ed[t2][t1]=i;
	}
	solve();
	memset(ed,0,sizeof(ed));
	F(i,1,n-3){
		ri t1=read(),t2=read();
		ed[t1][t2]=ed[t2][t1]=i;
	}
	tar=1;
	solve();
	write(cnt+cntt,'\n');
	F(i,1,cnt){
		write(ans[i].first,' ');
		write(ans[i].second,'\n');
	}
	reverse(anss+1,anss+cntt+1);
	F(i,1,cntt){
		write(anss[i].first,' ');
		write(anss[i].second,'\n');
	}
	return 0;
}