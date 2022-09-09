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
int n,m,a1[200002],a2[200002],b1[200002],b2[200002],temp,cnt1,cnt2,cnt3,cnt4,ak[200002],cnt;
inline int solve(int *a,int *b){
	sort(a+1,a+((a==a1)?cnt1:cnt2)+1);
	sort(b+1,b+((b==b1)?cnt3:cnt4)+1);
	ri n=((a==a1)?cnt1:cnt2),m=((b==b1)?cnt3:cnt4);
	cnt=0;
	F(i,1,n){
		if(binary_search(b+1,b+m+1,a[i]))ak[++cnt]=a[i];
	}ri ans=cnt;
	ri tot=0;
	F(i,1,m){
		while(tot<n&&a[tot+1]<=b[i]+tot)++tot;
		ans=max(1ll*ans,(long long)(cnt-(lower_bound(ak+1,ak+cnt+1,b[i]+tot)-ak-1)+(lower_bound(b+1,b+m+1,b[i]+tot)-lower_bound(b+1,b+m+1,b[i]))));
		
	}return ans;
}
int main() {
	F(qwq,1,read()){
		cin>>n>>m;cnt1=cnt2=cnt3=cnt4=0;
		F(i,1,n){
			temp=read();
			if(temp<0)a1[++cnt1]=-temp;
			else a2[++cnt2]=temp;
		}F(i,1,m){
			temp=read();
			if(temp<0)b1[++cnt3]=-temp;
			else b2[++cnt4]=temp;
		}
		write(
		solve(a1,b1)+
		solve(a2,b2)
		,'\n');
	}
	return 0;
}