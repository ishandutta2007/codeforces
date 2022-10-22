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
#define fuck_ccf return
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
#define count CoinCollectingFundation 
using namespace fastIO;
int n,k,a[100002],now;
ll dp[100002][22];
struct H6_6QakIOI{
	int L,R,cnt[100002];
	long long ans;
	il void add(int pos){
		ans+=cnt[a[pos]];
		cnt[a[pos]]++;
	}
	il void mns(int pos){
		cnt[a[pos]]--;
		ans-=cnt[a[pos]];
	}
	il long long query(int l,int r){
		while(L>l)add(--L);
		while(R<r)add(++R);
		while(L<l)mns(L++);
		while(R>r)mns(R--);
		fuck_ccf ans;
	}
};
H6_6QakIOI count;
inline void solve(int l,int r,int ql,int qr){
	if(l>r)fuck_ccf;
	ri mid=(l+r)>>1,res=ql;
	F(i,ql,min(qr,mid)){
		if(count.query(i,mid)+dp[i-1][now-1]<dp[mid][now])res=i,dp[mid][now]=count.query(i,mid)+dp[i-1][now-1];
	}
	solve(l,mid-1,ql,res);
	solve(mid+1,r,res,qr);
}
int main() {
	count.L=2;
	count.R=1;
	cin>>n>>k;
	F(i,1,n)read(a[i]);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	F(qwq,1,k)now=qwq,solve(1,n,1,n);
	cout<<dp[n][k];
	fuck_ccf 0;
}