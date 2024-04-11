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
#define mod 1000000007
int n,a[1919810],pw[1919810];
int mmin[10000002],mu[10000002];
int cnt[500002],f[500002][10],num[10000002],orz[114514],tot;
ll ans;
#define vis mmin
inline void dfs(int pos,int mul){
	if(pos>tot){
		++num[mul];
		return;
	}
	dfs(pos+1,mul);
	dfs(pos+1,mul*orz[pos]);
}
int main() {
	mmin[1]=1;mu[1]=1;pw[0]=1;pw[1]=2;F(i,2,1919808)pw[i]=pw[i-1]*2%mod;F(i,0,1919808)pw[i]--;
	F(i,2,10000000){
		if(!mmin[i]){
			mu[i]=-1;
			for(ri j=i;j<=10000000;j+=i){
				if(!mmin[j])mmin[j]=i;
			}
		}else{
			if((i/mmin[i])%mmin[i])mu[i]=mu[mmin[i]]*mu[i/mmin[i]];
		}
	}
	cin>>n;
	F(i,1,n){
		read(a[i]);
	}
	F(i,1,n){
		tot=0;
		ri temp=a[i];
		while(temp!=1){
			if(orz[tot]!=mmin[temp])orz[++tot]=mmin[temp];
			temp/=mmin[temp];
		}//F(i,1,tot)cerr<<orz[i]<<' ';cerr<<endl;
		dfs(1,1);
	}
	F(i,1,10000000){
		ans+=pw[num[i]]*mu[i];
	}
	ans=(ans%mod+mod)%mod*n%mod;
	F(i,1,10000000){
		ans-=1ll*num[i]*pw[num[i]]%mod*mu[i];
	}ans=-ans;
	cout<<(ans%mod+mod)%mod;
	return 0;
}