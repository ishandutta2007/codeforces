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
struct ed{
	int u,v,l,r;
	inline bool operator<(const ed &b)const{
		return l>b.l;
	}
};
priority_queue<ed>q;
vector<ed>res[500002][2];
int dp[500002][2],n,m;
inline void orz(ed x){//cerr<<x.u<<' '<<x.v<<' '<<x.l<<' '<<x.r<<endl;
	if(dp[x.u][x.l&1]>=x.l){//cerr<<x.u<<' '<<x.v<<' '<<x.l<<' '<<x.r<<endl;
		if(x.v==n){
			cout<<x.l+1;
			exit(0);
		}
		dp[x.v][x.l+1&1]=max(dp[x.v][x.l+1&1],x.r+1);
		for(ed i:res[x.v][x.l+1&1])q.push(ed{i.u,i.v,x.l+1,i.r});
		res[x.v][x.l+1&1].clear();
	}else res[x.u][x.l&1].push_back(x);
}
int main() {
	memset(dp,0xff,sizeof(dp));
	dp[1][0]=0;
	cin>>n>>m;
	if(n==1){
		puts("0");
		cerr<<"FUCK CCF,YOU THINK YOU CAN BEAT ME???";
		return 0;
	}
	F(i,1,m){
		int u,v,l,r;
		read(u,v,l,r);--r;
		q.push(ed{u,v,l,r-(r-l&1)});
		q.push(ed{v,u,l,r-(r-l&1)});
		q.push(ed{u,v,l+1,r-(r-l+1&1)});
		q.push(ed{v,u,l+1,r-(r-l+1&1)});
	}
	while(!q.empty()){
		ed x=q.top();
		q.pop();
		if(x.r>=x.l)
		orz(x);
	}
	puts("-1");
	return 0;
}