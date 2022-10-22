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
#define ll __int128
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
__int128 mod;
template<int N,int M>
struct mat {
	__int128 v[N+1][M+1];
	mat() {
		memset(v,0,sizeof(v));
	}
	__int128 & operator()(register int xpos,register int ypos) {
		return v[xpos][ypos];
	}
	__int128 * operator[](register int xpos) {
		return v[xpos];
	}
	inline int Nsize() {
		return N;
	} inline int Msize() {
		return M;
	}
};
mat<2,2>base;
inline mat<2,2>make_mat(__int128 a,__int128 b,__int128 c,__int128 d) {
	mat<2,2>rt;
	rt[1][1]=a,rt[1][2]=b,rt[2][1]=c,rt[2][2]=d;
	return rt;
}
template<int N,int M,int K>
inline mat<N,K> operator*(mat<N,M> a,mat<M,K> b) {
	mat<N,K>rt;
	for(register int i=1; i<=N; i++) {
		for(register int j=1; j<=K; j++) {
			for(register int k=1; k<=M; k++) {
				rt.v[i][j]+=a.v[i][k]*b.v[k][j];

				rt.v[i][j]%=mod;

			}
		}
	}
	return rt;
}
template<int N,int M>
inline mat<N,M> operator*(mat<N,M> a,__int128 x) {
	mat<N,M>rt;
	for(register int i=1; i<=N; i++) {
		for(register int j=1; j<=M; j++) {

			rt.v[i][j]=a.v[i][j]*x%mod;

		}
	}
	return rt;
}
template<int N,int M>
inline mat<N,M> operator+(mat<N,M> a,mat<N,M> b) {
	mat<N,M>rt;
	for(register int i=1; i<=N; i++) {
		for(register int j=1; j<=M; j++) {

			rt.v[i][j]=((a.v[i][j]+b.v[i][j]<mod)?(a.v[i][j]+b.v[i][j]):(a.v[i][j]+b.v[i][j]-mod));

		}
	}
}
template<int N>
inline mat<N,N> pow(mat<N,N> bot,__int128 p) {
	mat<N,N>rt;
	F(i,1,N)rt.v[i][i]=1;
	while(p) {
		if(p&1) {
			rt=rt*bot;
		}
		bot=bot*bot,p>>=1;
	}
	return rt;
}
inline __int128 getfib(__int128 x) {
	return (make_mat(1,0,0,0)*pow(base,x-1))[1][1];
}
__int128 x,len=150000,p[1919810],f[150002],cnt,num,nxt[1919810];
int main() {
	mod=10000000000000ll;
	base=make_mat(1,1,1,0);
	read(x);
	if(x==0)puts("0");
	else if(x==1)puts("1");
	else {
		mod=100000;
		f[1]=1;
		F(i,2,150000) {
			f[i]=(f[i-1]+f[i-2])%mod;
			if(f[i]==x%mod) {
				p[++cnt]=i;
			}

		}
		if(!cnt) {
			puts("-1");
			return 0;
		}
		F(i,1,8) {
			mod*=10;
			F(pos,1,cnt) {

				F(j,1,10) {
					if(getfib(p[pos])==x%mod) {
						nxt[++num]=p[pos];
					}
					p[pos]+=len;
				}

			}
			len*=10;
			cnt=num;num=0;
			F(i,1,cnt)p[i]=nxt[i];
		}
		if(cnt)write(*min_element(p+1,p+cnt+1));

	}

	return 0;
}