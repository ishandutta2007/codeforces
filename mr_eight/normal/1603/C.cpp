//#include <bits/stdc++.h>
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
#define mod 998244353
int n,a[100002],qwq[1002],qaq[1002],dp[100002],nxt[100002],cnt,tot,now;
ll ans;
int main() {
	F(iakioi,1,read()){
		cin>>n;
		F(i,1,n)read(a[i]);
		dp[a[n]]=1;
		qwq[cnt=1]=a[n];
		UF(i,n-1,1){
			tot=0;now=cnt+1;
			for(int l=1,r;l<=a[i];l=r+1){
				ll sum=0;bool tag=false;
				if(a[i]>l)r=(a[i]-1)/((a[i]-1)/l);
				else r=a[i];
				int d=(a[i])/l,u=(a[i]-1)/l+1;
				if(qaq[tot]!=d)qaq[++tot]=d;
				else tag=true;
				while(now>1&&qwq[now-1]>=u){
					--now;
					sum+=dp[qwq[now]];
				}
				if(tag)nxt[d]=(nxt[d]+sum)%mod;
				else nxt[d]=sum%mod;
				ans+=sum%mod*i%mod*(l-1)%mod;//cerr<<i<<" "<<l<<" "<<d<<" "<<u<<" "<<sum<<" "<<ans<<endl;
			}
			++nxt[a[i]];
			#define i ii
			F(i,1,cnt)dp[qwq[i]]=0;
			cnt=tot;
			F(i,1,cnt)qwq[i]=qaq[i];
			F(i,1,cnt)dp[qwq[i]]=nxt[qwq[i]];
			reverse(qwq+1,qwq+cnt+1);//F(j,1,cnt)cerr<<qwq[j]<<' '<<dp[qwq[j]]<<endl;cerr<<endl;
			#undef i
			//cerr<<ans<<endl;
		}
	//	if(iakioi==66){
	//		F(j,1,n)write(a[j],' ');return 0;
	//	}
		write(ans%mod,'\n');
		ans=0;
	}
	return 0;
}
/*
1
3
2 3 1
*/