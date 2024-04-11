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
bool orz[202][202],tag[114514],vis[114514];
int n,m,t1,t2;
int dis[202][202],ans[202];
inline void dfs(int pos){
	vis[pos]=1;
	F(i,1,n){
		if(orz[pos][i]){
			if(vis[i]){
				if(tag[pos]==tag[i]){
					puts("NO");
					exit(0);
				}
			}else{
				tag[i]=!tag[pos];
				dfs(i);
			}
		}
	}
}
int main() {
	memset(dis,0x3f,sizeof(dis));
	cin>>n>>m;
	F(i,1,n)dis[i][i]=0;
	F(i,1,m){
		read(t1);read(t2);
		if(read()){
			orz[t1][t2]=orz[t2][t1]=1;
			dis[t1][t2]=1;
			dis[t2][t1]=-1;
		}else{
			orz[t1][t2]=orz[t2][t1]=1;
			dis[t1][t2]=dis[t2][t1]=1;
		}
	}
	dfs(1);

		bool kk=0;
		F(k,1,n)F(i,1,n)F(j,1,n)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		F(i,1,n)ans[i]=*max_element(dis[i]+1,dis[i]+n+1),kk=(kk||dis[i][i]<0);
		ri pos=max_element(ans+1,ans+n+1)-ans;
		if(kk){
			puts("NO");
			return 0;
		}puts("YES");
		write(ans[pos],'\n');
		F(i,1,n)write(dis[pos][i],' ');
		cerr<<endl<<"FUCK CCF!!!";
	
	return 0;
}