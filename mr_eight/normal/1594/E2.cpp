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
#define mod 1000000007
ll dp[62],n,m,a;
map<ll,ll*>f;
map<ll,int>col;
char temp[10];
inline int getv(){
	scanf("%s",temp);
	if(temp[0]=='w')return 0;
	if(temp[0]=='y')return 1;
	if(temp[0]=='g')return 2;
	if(temp[0]=='b')return 3;
	if(temp[0]=='r')return 4;
	return 5;
}
inline bool ok(int x,int y){
	return x!=y&&(x^y)!=1;
}
inline ll orz(ll x,int y){
	if(f.count(x))return f[x][y];
	return dp[n-(63-__builtin_clzll(x))];
}
inline ll* newll(){
	ll *x=new ll[6];
	F(i,0,5)x[i]=0;
	return x;
}
int main() {
	cin>>n;--n;cin>>m;
	dp[0]=1;
	F(i,1,n){
		dp[i]=16*dp[i-1]%mod*dp[i-1]%mod;
	}
	//cout<<(dp[n]*6)%mod;
	F(i,1,m){
		read(a);
		col[a]=getv();
		while(a){
			if(!f.count(a)){
				f[a]=newll();
			}
			a>>=1;
		}
	}
	for(auto i=--f.end();;--i){
		ll pos=i->first;
		if(63-__builtin_clzll(pos)==n){
			i->second[col[pos]]=1;
			
		}else{
		F(qwq,0,5){
			ll multi=0,m2=0;
			F(qaq,0,5)if(ok(qwq,qaq)){
				multi=(multi+orz(pos<<1,qaq))%mod;
				m2=(m2+orz(pos<<1|1,qaq))%mod;
			}
			i->second[qwq]=multi*m2%mod;//if(pos==2)cerr<<multi<<' '<<m2<<' '<<orz(5,5)<<endl;
		}
		if(col.count(pos)){
			int c=col[pos];
			F(qwq,0,5)if(qwq!=c)i->second[qwq]=0;
		}	
		}
	//	F(i,0,5)cerr<<f[pos][i]<<' ';
		if(i==f.begin())break;
	}
	ll ans=0;
	F(i,0,5)ans+=orz(1,i);
	write(ans%mod);
	return 0;
}