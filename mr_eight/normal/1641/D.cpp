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
#pragma GCC diagnostic error "-std=c++14"
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
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
bitset<100000>b[20002],temp;
int n,m;
struct S{
	int a[6],w;
	inline bool operator<(const S &b)const{
		return w<b.w;
	}
}v[100002];
vector<int>p[500002];
int t[1000002],cnt,ans=INT_MAX;
int main() {
	cin>>n>>m;
	F(i,0,n-1){
		F(j,1,m)read(v[i].a[j]),t[++cnt]=v[i].a[j];
		read(v[i].w);
	}
	sort(v,v+n);sort(t+1,t+cnt+1);
	F(i,0,n-1)F(j,1,m)p[lower_bound(t+1,t+cnt+1,v[i].a[j])-t].push_back(i);
/*	F(i,1,cnt){
		cerr<<i<<" ";for(int j:p[i])cerr<<j<<" ";cerr<<endl;
	}
*/	temp.reset();
	for(int l=0,r;l<n;l=r+1){
		r=min(n-1,l+19999);
		F(i,0,r-l)b[i].set();
		F(i,1,cnt){
				for(int j:p[i])temp[j]=0;
				for(int j:p[i])if(l<=j&&j<=r)b[j-l]&=temp;
				for(int j:p[i])temp[j]=1;
		}
		F(i,0,r-l){
			int pos=b[i]._Find_first();
			if(pos<n)ans=min(ans,v[i+l].w+v[pos].w);
		}
	}
	if(ans!=INT_MAX)cout<<ans;
	else puts("-1");
	return 0;
}