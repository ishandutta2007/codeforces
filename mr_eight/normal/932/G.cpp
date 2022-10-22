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
#define mod 1000000007ll
#define dp ans
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
const int MAXN=1000005;
int len[MAXN],ch[MAXN][26],fail[MAXN],cnt,lst,up[MAXN],orz[MAXN];
ll qwq[MAXN],dp[MAXN];
char c[MAXN],ccf[MAXN];
int now,n;
inline void insert(int pos){
	while(c[pos]!=c[pos-len[lst]-1])lst=fail[lst];
	if(!ch[lst][c[pos]-97]){
		len[++cnt]=len[lst]+2;
		ri i=fail[lst];
		while(c[pos]!=c[pos-len[i]-1])i=fail[i];
		fail[cnt]=ch[i][c[pos]-97];
		ch[lst][c[pos]-97]=cnt;
		orz[cnt]=len[cnt]-len[fail[cnt]];
		if(orz[cnt]==orz[fail[cnt]])up[cnt]=up[fail[cnt]];
		else up[cnt]=fail[cnt];
	}lst=ch[lst][c[pos]-97];
}
int main() {
	len[1]=-1;
	fail[0]=1;
	up[0]=1;
	ans[0]=1;
	cnt=1;scanf("%s",ccf+1);n=strlen(ccf+1);
	if(n%2){
		cerr<<"Fuck CCF!!!"<<endl;
		cout<<0;
		return 0;
	}
	F(i,1,n/2){
		c[2*i-1]=ccf[i];
		c[i<<1]=ccf[n-i+1];
	}F(i,1,n){
		insert(i);
		for(ri j=lst;j;j=up[j]){
			qwq[j]=ans[i-len[up[j]]-orz[j]];
			if(up[j]!=fail[j])qwq[j]+=qwq[fail[j]];
			qwq[j]%=mod;
			if(!(i&1))ans[i]+=qwq[j],ans[i]%=mod;
		}
	}cout<<ans[n];
	return 0;
}