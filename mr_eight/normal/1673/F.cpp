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
#include <random>
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
int n=32,k;
int cnt,S=0b1001010101,T=0b0110101010,a[35][35];
vector<int>v[35],w[35];
map<int,pii >p;
inline void solve(int l,int r,int s){
	if(l==r)return;
	int mid=(l+r)>>1;
	int h=31-__builtin_clz(s);
	solve(l,mid,s^(1<<h));
	F(i,mid+1,r)F(j,1,n)v[i][j]^=(1<<h);
	solve(mid+1,r,s^(1<<h));
	reverse(v+mid+1,v+r+1);
}
inline void solve2(int l,int r,int s){
	if(l==r)return;
	int mid=(l+r)>>1;
	int h=31-__builtin_clz(s);
	solve2(l,mid,s^(1<<h));
	F(i,mid+1,r)F(j,1,n)w[i][j]^=(1<<h);
	solve2(mid+1,r,s^(1<<h));
	reverse(w+mid+1,w+r+1);
}
int main() {
	F(i,0,34)v[i].resize(35),w[i].resize(35);
	solve(1,32,S);
	solve2(1,32,T);
	ll sum=0;
	F(i,1,n)F(j,1,n)a[i][j]=v[i][j]^w[j][i],p[a[i][j]]={i,j};
	F(i,1,n)F(j,1,n-1)sum+=(a[i][j]^a[i][j+1]);
	F(i,1,n-1)F(j,1,n)sum+=(a[i][j]^a[i+1][j]);
//	cerr<<sum<<endl;
	cin>>n>>k;
	F(i,1,n){
		F(j,1,n-1)write(a[i][j]^a[i][j+1]," \n"[j==n-1]);
		fflush(stdout);
	}
	F(i,1,n-1){
		F(j,1,n)write(a[i][j]^a[i+1][j]," \n"[j==n]);
		fflush(stdout);
	}
	int x=0;
	F(i,1,k){
		int nxt;
		cin>>nxt;
		x^=nxt;
		write(p[x].first,' ');
		write(p[x].second,'\n');
		fflush(stdout);
	}
	return 0;
}