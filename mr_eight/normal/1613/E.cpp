//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
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
//#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
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
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
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
	inline void write(T x) {
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
int n,m,x,y;
vector<char>c[1000002];
vector<bool>vis[1000002];
queue<pii >q;
inline bool check(int x,int y){
	if(c[x][y]!='.')return false;
	int cnt=(c[x-1][y]=='.')+(c[x+1][y]=='.')+(c[x][y-1]=='.')+(c[x][y+1]=='.')
	+(c[x-1][y]=='L')+(c[x+1][y]=='L')+(c[x][y-1]=='L')+(c[x][y+1]=='L'),
	tot=vis[x-1][y]+vis[x+1][y]+vis[x][y-1]+vis[x][y+1];
	return tot>=cnt-1;
}
int main() {
	F(iakioi,1,read()){
		read(n,m);
		F(i,0,n+1)c[i].clear(),c[i].resize(m+2),vis[i].clear(),vis[i].resize(m+2);
		F(i,1,n)scanf("%s",c[i].begin()+1);
		F(i,1,n)F(j,1,m)if(c[i][j]=='L')x=i,y=j;
		vis[x][y]=true;
		q.push(make_pair(x,y));
		while(!q.empty()){
			x=q.front().first,y=q.front().second;
			q.pop();
			if(!vis[x-1][y])if(check(x-1,y)){
				vis[x-1][y]=true;
				q.push(make_pair(x-1,y));
			}
			if(!vis[x+1][y])if(check(x+1,y)){
				vis[x+1][y]=true;
				q.push(make_pair(x+1,y));
			}
			if(!vis[x][y-1])if(check(x,y-1)){
				vis[x][y-1]=true;
				q.push(make_pair(x,y-1));
			}
			if(!vis[x][y+1])if(check(x,y+1)){
				vis[x][y+1]=true;
				q.push(make_pair(x,y+1));
			}
		}
		F(i,1,n){
			F(j,1,m){
				if(c[i][j]=='L'||!vis[i][j])putchar(c[i][j]);
				else putchar('+');
			}
			putchar('\n');
		}
	}
	return 0;
}