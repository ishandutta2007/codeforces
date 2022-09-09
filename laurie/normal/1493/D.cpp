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
		if(x==0) {
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
const long long mod=1e9+7;
inline long long pw(long long x,long long p) {
	long long res=1;
	for(; p; p>>=1,x=x*x%mod)
		if(p&1)res=res*x%mod;
	return res;
}
inline long long getm(long long top,long long bot) {
	return (top*pw(bot,mod-2))%mod;
}
bool mark[200002];
int cnt[200002],r[200002][50],n;
ll ans[800002];
#define m 200000
#include<tr1/unordered_map>
using tr1::unordered_map;
unordered_map<int,int>num[800002];
#define mid (l+r>>1)
inline bool add(ri pos,ri l,ri r,ri q,ri v) {
	if(l==r) {
		ans[pos]=ans[pos]*v%mod;
		num[pos][v]++;
		return 1;
	}
	if(q<=mid) {
		if(add(pos<<1,l,mid,q,v)) {
			if(num[pos<<1][v]<=num[pos<<1|1][v]) {
				ans[pos]=ans[pos]*v%mod;
				num[pos][v]++;
				return 1;
			}
		}
	}else{
		if(add(pos<<1|1,mid+1,r,q,v)) {
			if(num[pos<<1][v]>=num[pos<<1|1][v]) {
				ans[pos]=ans[pos]*v%mod;
				num[pos][v]++;
				return 1;
			}
		}
	}return 0;
}
int main() {
	mark[1]=1;
	F(i,2,m) {
		if(!mark[i]) {
			for(ri j=i; j<=m; j+=i) {
				mark[j]=1;
				ri temp=j;
				while(temp%i==0)r[j][++cnt[j]]=i,temp/=i;
			}
		}
	}ri q;
	cin>>n>>q;
	F(i,1,800000)ans[i]=1;
//	ri nn=1;
//	while(nn<n)nn<<=1;
//	n=nn;
ri temp;
	F(i,1,n) {
		read(temp);
		F(j,1,cnt[temp])add(1,1,n,i,r[temp][j]);
	}
	F(ak,1,q) {
		ri i=read(),temp=read();
		F(j,1,cnt[temp])add(1,1,n,i,r[temp][j]);
		write(ans[1],'\n');
	}
	return 0;
}