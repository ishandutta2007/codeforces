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
bool tag[20000002];
int pri[2000002],cnt,ans[6002],n;
inline void solve(int x,int kkksc03){
	UF(i,n,1)if(!ans[i]&&x>=i)x-=i,ans[i]=kkksc03;
}
int main() {
	tag[1]=true;
	F(i,2,20000000){
		if(!tag[i])pri[++cnt]=i;
		for(int j=1,k=(i<<1);k<=20000000;k=i*pri[++j]){
			tag[k]=true;
			if(i%pri[j]==0)break;
		}
	}
	cin>>n;
	if(n==1){
		puts("-1");
		return 0;
	}
	int x=n*(n+1)/2;
	if(!tag[x]){
		F(i,1,n)write(1,' ');
		return 0;
	}
	if(!tag[x-2]){
		write(1,' ');write(2,' ');
		F(i,1,n-2)write(1,' ');
		return 0;
	}
	if(x%2==0){
		F(i,1,x)if(!tag[i]&&!tag[x-i]){
			solve(i,1);
			F(j,1,n){
				if(ans[j])write(1,' ');
				else write(2,' ');
			}
			return 0;
		}
	}else{
		UF(i,n,1)if(!tag[i]){
			ans[i]=3;
			x-=i;
			break;
		}
		F(i,1,x)if(!tag[i]&&!tag[x-i]){
			solve(i,1);
			F(j,1,n){
				if(ans[j])write(ans[j],' ');
				else write(2,' ');
			}
			return 0;
		}
	}
	return 0;
}