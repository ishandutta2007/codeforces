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
int n,k,ak[202];
char c[1000002],ans[1000002];
bool orz[1000002];
inline bool ok(char x) {
	ak[x]++;
	ri qwq=0;
	F(i,'a','z') {
		qwq+=(ak[i]+k-1)/k;
	}
	ak[x]--;
	return qwq<=n/k;
}
inline bool okk(char x,char y) {
	if(y>'z')return 0;
	ak[x]++;
	ri qwq=0;
	bool f=0;
	F(i,'a','z') {
		qwq+=(ak[i]+k-1)/k;
		if(i>=y) {
			if(ak[i]%k!=0)f=1;
		}
	}
	ak[x]--;
	if(f)return qwq<=n/k;
	else return qwq<n/k;
}
int main() {
	F(qwq,1,read()) {
		cin>>n>>k;
		F(i,1,n)orz[i]=0;
		scanf("%s",c+1);
		memset(ak,0,sizeof(ak));
		ans[n+1]='\0';
		ri lst=0;
		F(i,1,n) {
			if(ok(c[i]));
			else break;
			if(i==n||okk(c[i],c[i+1]+1))orz[i]=1;
			lst=i;
			ak[c[i]]++;
		}
		UF(i,lst,1) {
			if(orz[i]) {
				UF(ii,i,1) {
					orz[ii]=1;
					
				}goto fi;
			}
		}
fi:
		;
		memset(ak,0,sizeof(ak));
		if(n%k) {
			puts("-1");
			continue;
		}
		bool flag=0;
		F(i,1,n) {
			if(!flag) {
				if(orz[i])ak[c[i]]++,ans[i]=c[i];
				else {
					F(j,c[i]+1,'z') {
						if(ok(j)) {
							ak[j]++;
							ans[i]=j;
							break;
						}
					}
					flag=1;
				}
			} else {
				F(j,'a','z') {
					if(ok(j)) {
						ak[j]++;
						ans[i]=j;
						break;
					}
				}
			}

		}
		puts(ans+1);
	}
	return 0;
}