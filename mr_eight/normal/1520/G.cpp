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
int n,m,w,mp[2002][2002];
queue<pii>q;
ll dis1[2002][2002],dis2[2002][2002],tot1=1e18,tot2=1e18;
inline void bfs(int x,int y){
	#define dis dis1
	memset(dis,0x3f,sizeof(dis));
	q.push(make_pair(x,y));	
	dis[x][y]=0;
	while(!q.empty()){
		x=q.front().first,y=q.front().second;
		q.pop();
		if(dis[x-1][y]>dis[x][y]+w&&mp[x-1][y]>=0){
			q.push(make_pair(x-1,y));
			dis[x-1][y]=dis[x][y]+w;
		}if(dis[x+1][y]>dis[x][y]+w&&mp[x+1][y]>=0){
			q.push(make_pair(x+1,y));
			dis[x+1][y]=dis[x][y]+w;
		}if(dis[x][y-1]>dis[x][y]+w&&mp[x][y-1]>=0){
			q.push(make_pair(x,y-1));
			dis[x][y-1]=dis[x][y]+w;
		}if(dis[x][y+1]>dis[x][y]+w&&mp[x][y+1]>=0){
			q.push(make_pair(x,y+1));
			dis[x][y+1]=dis[x][y]+w;
		}
	}
	#undef dis
}
inline void bfs2(int x,int y){
	#define dis dis2
	memset(dis,0x3f,sizeof(dis));
	q.push(make_pair(x,y));	
	dis[x][y]=0;
	while(!q.empty()){
		x=q.front().first,y=q.front().second;
		q.pop();
		if(dis[x-1][y]>dis[x][y]+w&&mp[x-1][y]>=0){
			q.push(make_pair(x-1,y));
			dis[x-1][y]=dis[x][y]+w;
		}if(dis[x+1][y]>dis[x][y]+w&&mp[x+1][y]>=0){
			q.push(make_pair(x+1,y));
			dis[x+1][y]=dis[x][y]+w;
		}if(dis[x][y-1]>dis[x][y]+w&&mp[x][y-1]>=0){
			q.push(make_pair(x,y-1));
			dis[x][y-1]=dis[x][y]+w;
		}if(dis[x][y+1]>dis[x][y]+w&&mp[x][y+1]>=0){
			q.push(make_pair(x,y+1));
			dis[x][y+1]=dis[x][y]+w;
		}
	}
	#undef dis
}
int main() {
	cin>>n>>m>>w;
	F(i,0,m+1)mp[0][i]=mp[n+1][i]=-1;
	F(i,0,n+1)mp[i][0]=mp[i][m+1]=-1;
	F(i,1,n){
		F(j,1,m){
			read(mp[i][j]);
		}
	}bfs(1,1);
	bfs2(n,m);
	F(i,1,n){
		F(j,1,m){
			if(mp[i][j]>0)tot1=min(dis1[i][j]+mp[i][j],tot1);
		}
	}F(i,1,n){
		F(j,1,m){
			if(mp[i][j]>0)tot2=min(dis2[i][j]+mp[i][j],tot2);
		}
	}tot1=min(tot1+tot2,dis1[n][m]);
	if(tot1<1e17)cout<<tot1;
	else cout<<-1;
	return 0;
}
/*
5 5
1
100 80 -1 -1 2
0 -1 1 -1 0
0 0 0 -1 0
-1 -1 -1 -1 -1
2 4 6 0 0
*/