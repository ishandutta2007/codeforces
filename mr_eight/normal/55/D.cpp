#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
#define F(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
#define Fc(i,a,b) for(char i=a,i##end=b;i<=i##end;++i)
#define Fs(i,a,b) for(short i=a,i##end=b;i<=i##end;++i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
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
inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
inline int getlcm(int x,int y){
	if(y==0)return x;
	return x/gcd(x,y)*y;
}
ll dp[19][49][2520][2];
int id[2521],cnt,orz[49],lcm[49][10],to[2520<<1],pww[20][10];
inline void push(int x){id[x]=++cnt;orz[cnt]=x;}
inline ll solve(ll x){
	memset(dp,0,sizeof(dp));
	F(i,0,x%10)dp[0][id[i]][i][0]=1;
	F(i,x%10+1,9)dp[0][id[i]][i][1]=1;
	char pw=0;
	F(i,0,17){
		x/=10;ri e=x%10;++pw;
		F(j,1,48)F(k,0,2519)Fc(l,0,1)if(dp[i][j][k][l]){
			F(a,0,e-l){
				dp[i+1][lcm[j][a]][to[pww[pw][a]+k]][0]+=dp[i][j][k][l];
			}
			F(a,e-l+1,9){
				dp[i+1][lcm[j][a]][to[pww[pw][a]+k]][1]+=dp[i][j][k][l];
			}
		}	
	}
	ll ans=0;
	F(j,1,48)F(k,0,2519)if(k%orz[j]==0)ans+=dp[18][j][k][0];
	return ans;
}
int main() {
	F(i,0,9)pww[0][i]=i;
	F(i,1,18)F(j,0,9)pww[i][j]=pww[i-1][j]*10%2520;
	F(i,0,5039)to[i]=i%2520;
	for(int i=1;i<=8;i<<=1)for(int j=1;j<=9;j*=3)for(int k=1;k<=5;k+=4)for(int l=1;l<=7;l+=6)push(i*j*k*l);
	F(i,1,48)F(j,0,9)lcm[i][j]=id[getlcm(orz[i],j)];id[0]=1;
	F(iakioi,1,read()){
		ll l,r;
		read(l,r);
		write(solve(r)-solve(l-1),'\n');
	}
	return 0;
}