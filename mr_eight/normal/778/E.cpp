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
int a[1005],len,n,num[1005],lst[1005],tot[11],c[10],lala,dp[1005][1005];
int b[1005][1005],l[1005],NOW,zz[30]= {0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9};
char s[1005];
inline void qwqaq(int *x,int &L) {
	scanf("%s",s);
	L=strlen(s);
	UF(i,L-1,0) {
		if(s[i]!='?')x[L-i]=s[i]-'0';
		else x[L-i]=-1;
	}
}
inline bool cmp(int x,int y) {
	return b[x][NOW]>b[y][NOW];
}
inline int st(int pos) {
	if(a[pos]>=0)return a[pos];
	return (pos==lala)?1:0;
}
inline int ed(int pos) {
	if(a[pos]>=0)return a[pos];
	return 9;
}
int main() {
//	freopen("dights.in","r",stdin);
//	freopen("dights.out","w",stdout);
	qwqaq(a,len);
	read(n);
	F(i,1,n)qwqaq(b[i],l[i]);
	lala=len;
	len=1001;
	F(i,0,9)read(c[i]);
	F(i,1,n)num[i]=i;
	memset(dp,-0x3f,sizeof(dp));
	dp[0][0]=0;
	F(i,1,len) {
		NOW=i;
		memcpy(lst,num,sizeof(lst));
		stable_sort(num+1,num+n+1,cmp);
		F(k,st(i),ed(i)) {
			memset(tot,0,sizeof(tot));
			F(j,1,n) {
				if(max(lala,l[j])>=i)++tot[b[j][i]];
			}
			F(j,0,n) {
				if(j) {
					ri pos=lst[j];
					if(max(lala,l[pos])>=i)--tot[b[pos][i]];
					++tot[b[pos][i]+1];
				}
				ri ans=0,nxt=0;
				F(orz,0,10)ans+=c[zz[orz+k]]*tot[orz];
				F(orz,10-k,10)nxt+=tot[orz];
				dp[i][nxt]=max(dp[i][nxt],dp[i-1][j]+ans);
			}
		}
	}
	write(dp[len][0]);
	return 0;
}