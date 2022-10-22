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
	char num[40];
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
			num[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(num[ -- cnt ]) ;
	}
}
using namespace fastIO;
int t,n,m,ans,up[502][502],l[502][502],r[502][502];
char c[502][502];
int main() {
	cin>>t;
	while(t--) {
		ans=0;
		cin>>n>>m;
		F(i,1,n)scanf("%s",c[i]+1);
		memset(up,0,sizeof(up));
		memset(l,0,sizeof(l));
		memset(r,0,sizeof(r));
		F(i,1,n){
			F(j,1,m){
				if(c[i][j]=='*')up[i][j]=up[i-1][j]+1;
			}
		}F(i,1,n){
			F(j,1,m){
				l[i][j]=min(up[i][j],l[i][j-1]+1);
			}
		}F(i,1,n){
			UF(j,m,1){
				r[i][j]=min(up[i][j],r[i][j+1]+1);
			}
		}F(i,1,n){
			UF(j,m,1){
				ans+=min(l[i][j],r[i][j]);
			}
		}cout<<ans<<endl;
	}
	return 0;
}