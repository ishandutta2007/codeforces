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
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
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
int n,K,f[202][202];
ll sz[202][202];
ll g[202][202];
pii node[202];
inline pii operator-(const pii &x,const pii &y){
	return make_pair(x.first-y.first,x.second-y.second);
}
inline ll cha(pii x,pii y){
	return 1ll*x.first*y.second-1ll*x.second*y.first;
}
inline bool check(ll x){
	memset(f,0,sizeof(f));memset(g,0,sizeof(g));
	F(len,3,n)
	UF(i,n,1){
		int jj=i+len-1;
		int j=jj;
		if(jj>n)j-=n;
		F(kk,i+1,jj-1){
			int k=kk;
			if(k>n)k-=n;
			int t1=f[i][k]+f[k][j];
			ll t2=g[i][k]+g[k][j]+sz[i][j]-sz[i][k]-sz[k][j];
			if(t2>=x)++t1,t2=0;
			if(t1>f[i][j]||(t1==f[i][j]&&t2>g[i][j])){
				f[i][j]=t1,g[i][j]=t2;
			}
		}
	}
	return f[1][n]>K;
}
int main() {
	cin>>n>>K;
	F(i,1,n)node[i]={read(),read()};
	ll tot=0;
	F(i,1,n-1)tot+=cha(node[i],node[i+1]);
	tot+=cha(node[n],node[1]);
	if(tot<0)tot=-tot;
	F(i,1,n){
		ll temp=0;
		F(j,i+1,n){
			temp+=cha(node[j-1],node[j]);
			sz[i][j]=cha(node[j],node[i])+temp;
			if(sz[i][j]<0)sz[i][j]=-sz[i][j];
			sz[j][i]=tot-sz[i][j];
		}
	}
	ll l=0,r=80000000000000000ll;
	while(l<r){
		ll mid=(l+r+1)/2;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}