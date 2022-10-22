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
int n,m,f[100002],temp[100002],res[100002];
vector<int>qwq[100002];
int vis[100002];
bool ak1[100002],ak2[100002];
inline bool cmp(int x,int y){
	return f[x]<f[y];
}
int main() {
	F(qwqwq,1,read()){
		read(n);read(m);
		F(i,1,n){f[i]=0;
			qwq[i].clear();
		}F(i,1,m)vis[i]=ak1[i]=ak2[i]=res[i]=0;
		F(i,1,m){
			ri ak;
			read(ak);res[i]=ak;
			F(ii,1,ak){
				qwq[ak=read()].push_back(i);f[ak]++;
			}
		}F(i,1,n)temp[i]=i;
		sort(temp+1,temp+n+1,cmp);
		ri cnt=0;
		F(ii,1,n){ri i=temp[ii],now=0;
			F(j,0,qwq[i].size()-1){
				if(!vis[qwq[i][j]]&&res[qwq[i][j]]==1){
					vis[qwq[i][j]]=i;
					now++;
				}res[qwq[i][j]]--;
			}if(now>(m+1)/2){
				puts("NO");
				goto nxt;
			}
			F(j,0,qwq[i].size()-1){if(now==(m+1)/2)break;
				if(!vis[qwq[i][j]]){
					vis[qwq[i][j]]=i;
					now++;
				}
			}
		}
		F(i,1,m){
			if(!vis[i]){
				puts("NO");
				goto nxt;
			}
		}puts("YES");F(i,1,m)write(vis[i],' ');putchar('\n');
		nxt:;
	}
	return 0;
}