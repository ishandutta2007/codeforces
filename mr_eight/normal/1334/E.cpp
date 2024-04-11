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
#define mod 998244353
ll x,y,p[15],cnt,a[15],b[15],C[102][102],ans;
int main(){
	F(i,0,100)C[i][0]=1;
	F(i,1,100)F(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	cin>>x;
	F(i,2,sqrt(x)){
		if(x%i==0){
			p[++cnt]=i;
			while(x%i==0)x/=i;
		}
	}
	if(x>1)p[++cnt]=x;
	//F(i,1,cnt)cerr<<p[i]<<" ";
	F(iakioi,1,read()){
		read(x);read(y);
		memset(a,0,sizeof(a));memset(b,0,sizeof(b));
		F(i,1,cnt)while(x%p[i]==0)x/=p[i],++a[i];
		F(i,1,cnt)while(y%p[i]==0)y/=p[i],++b[i];
		x=y=0;ans=1;
		F(i,1,cnt){
			if(a[i]<b[i]){
				ans=ans*C[x+b[i]-a[i]][x]%mod;
				x+=b[i]-a[i];
			}else{
				ans=ans*C[y+a[i]-b[i]][y]%mod;
				y+=a[i]-b[i];
			}
		}
		write(ans,'\n');
	}
    return 0;
}