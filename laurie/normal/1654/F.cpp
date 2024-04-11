
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
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
char a[1<<18|1002];
int n,N,res;
bool ok[1<<18|2];
#define mod 999999999999989
#define base 1331
const int B=3000;
ll v[1<<18],g[1<<18];
inline void solve() {
	ll temp;
	for(int i=1; i<N; i<<=1) {
		for(int j=i; j<N; j=(j+1)|i) {
			temp=g[j];
			g[j]=(g[j^i]-temp)%mod;
			(g[j^i]+=temp)%=mod;
		}
	}
	F(i,0,N-1)g[i]=v[i]*__int128(g[i])%mod;
	for(int i=1; i<N; i<<=1) {
		for(int j=i; j<N; j=(j+1)|i) {
			temp=g[j];
			g[j]=(g[j^i]-temp)%mod;
			(g[j^i]+=temp)%=mod;
		}
	}
	for(int i=0; i<N; ++i)if(g[i]<0)g[i]+=mod;
}
inline bool cmp(int x,int y,int pos){
	F(i,pos,min(pos+B,N)-1)if(a[x^i]!=a[y^i])return a[x^i]<a[y^i];
	return false;
}
int main() {//freopen("data.txt","r",stdin);
	cin>>n;
	scanf("%s",a);
	res=N=(1<<n);
	F(i,0,(1<<n)-1)ok[i]=true,v[i]=a[i];
	ll temp;
	for(int i=1; i<N; i<<=1) {
		for(int j=i; j<N; j=(j+1)|i) {
			temp=v[j];
			v[j]=(v[j^i]-temp)%mod;
			(v[j^i]+=temp)%=mod;
		}
	}int pos;
	for(int i=0; i<N; i+=B) {
		memset(g,0,sizeof(g));ll now=1;
		F(j,i,min(i+B,N)-1)g[j]=now,now=now*base%mod;
		solve();
		bool flag=false;
		F(j,0,N-1){
			if(ok[j]){
				if(!flag)now=g[j],pos=j,flag=true;
				else if(g[j]!=now){
					if(cmp(j,pos,i))pos=j,now=g[j];
					--res;
				}
			}
		}
		F(j,0,N-1)if(g[j]!=now)ok[j]=false;
		if(res==1)break;
	}
	F(i,0,N-1){
		if(ok[i]){
			F(j,0,N-1)putchar(a[i^j]);
			break;
		}
	}
	return 0;
}