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
int n,m,t1,t2;
int tak[602][602],w[602][602],dis[602];
bool vis[602];
int main() {
	cin>>n>>m;
	memset(tak,0x3f,sizeof(tak));
	memset(w,0x3f,sizeof(w));
	F(i,1,m){
		read(t1);read(t2);
		read(tak[t1][t2]);
	}
	F(i,0,n-1){
		ri p=min_element(tak[i],tak[i]+n)-tak[i];
		w[i][p]=tak[i][p];
		F(j,p+1,n-1){
			w[i][j]=min(w[i][j-1]+1,tak[i][j]);
		}
		w[i][0]=min(w[i][n-1]+1,tak[i][0]);
		F(j,1,p-1)w[i][j]=min(w[i][j-1]+1,tak[i][j]);
	}
	F(i,0,n-1){
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		dis[i]=0;ri p=-1;
		F(iakioi,2,n){
			p=-1;
			F(j,0,n-1){
				if(!vis[j]){
					if(p<0||dis[j]<dis[p])p=j;
				}
			}
			vis[p]=1;
			F(j,0,n-1)if(!vis[j])dis[j]=min(dis[j],dis[p]+w[p][(j-dis[p]%n+n)%n]);
		}
		F(j,0,n-1)write(dis[j],' ');
		putchar('\n');
	}
	return 0;
}