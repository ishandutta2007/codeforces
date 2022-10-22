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
#define int long long
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
#define mod 1000000007
template<int N,int M>
struct mat {
	long long v[N+1][M+1];
	mat() {
		memset(v,0,sizeof(v));
	}
	long long & operator()(register int xpos,register int ypos) {
		return v[xpos][ypos];
	}
	long long * operator[](register int xpos) {
		return v[xpos];
	}
	inline int Nsize() {
		return N;
	} inline int Msize() {
		return M;
	}
};
template<int N,int M,int K>
inline mat<N,K> operator*(mat<N,M> a,mat<M,K> b) {
	mat<N,K>rt;
	for(register int i=0; i<N; i++) {
		for(register int j=0; j<K; j++) {
			for(register int k=0; k<M; k++) {
				rt.v[i][j]+=a.v[i][k]*b.v[k][j];
#ifdef mod
				rt.v[i][j]%=mod;
#else
#warning mod is not defined
#endif
			}
		}
	}
	return rt;
}
template<int N,int M>
inline mat<N,M> operator*(mat<N,M> a,long long x) {
	mat<N,M>rt;
	for(register int i=1; i<=N; i++) {
		for(register int j=1; j<=M; j++) {
#ifdef mod
			rt.v[i][j]=a.v[i][j]*x%mod;
#else
			rt.v[i][j]=a.v[i][j]*x;
#endif
		}
	}return rt;
}
template<int N,int M>
inline mat<N,M> operator+(mat<N,M> a,mat<N,M> b) {
	mat<N,M>rt;
	for(register int i=1; i<=N; i++) {
		for(register int j=1; j<=M; j++) {
#ifdef mod
			rt.v[i][j]=((a.v[i][j]+b.v[i][j]<mod)?(a.v[i][j]+b.v[i][j]):(a.v[i][j]+b.v[i][j]-mod));
#else
			rt.v[i][j]=a.v[i][j]+b.v[i][j];
#endif
		}
	}
}
template<int N>
inline mat<N,N> pow(mat<N,N> bot,long long p) {
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
mat<31,31>orz[62][32],pre[32],suf[32],sto[62];
mat<1,31>now;
int n,k,m,nn;
inline int getorz(int pos){
	nn=n;
	F(i,1,pos)nn/=k;
	return nn%k;
}
signed main() {
	cin>>n>>k;nn=n;m=-1;
	while(nn)++m,nn/=k;
	F(i,0,k-1){
		F(j,0,k){
			orz[0][i][j][j]=1;
		}F(j,0,k)orz[0][i][j][i]=1;
	}F(i,0,k)sto[0][i][i]=1;
	F(i,1,m){
		pre[0]=orz[i-1][0];
		F(ii,1,k-1)pre[ii]=pre[ii-1]*orz[i-1][ii];
		suf[k-1]=orz[i-1][k-1];
		UF(ii,k-2,0)suf[ii]=orz[i-1][ii]*suf[ii+1];
		orz[i][0]=suf[0];
		sto[i]=sto[i-1]*suf[1];
		F(j,1,k-1)orz[i][j]=suf[j]*pre[j-1];
	}
	now[0][k]=1;ri qwq=0;
	UF(i,m,0){
		F(j,0,getorz(i)-1){
			now=now*orz[i][(j+qwq)%k];
		}
		qwq+=getorz(i);
	}ll ans=0;
	F(i,0,k)ans+=now[0][i];
	cout<<ans%mod;
	return 0;
}