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
ll n,q,t,a[1000002],can[2000002],cnt,temp1[100002],temp2[100002],c1,c2;
inline void dfs(int l,int r){
if(l>r)return;
	can[++cnt]=0;
	F(i,l,r)can[cnt]+=a[i];
	ri mmin=INT_MAX,mmax=0;
	F(i,l,r){
		mmin=min(mmin,(int)a[i]),mmax=max(mmax,(int)a[i]);
	}ri mid=mmax+mmin>>1;
	c1=c2=0;
	F(i,l,r){
		if(a[i]<=mid)temp1[++c1]=a[i];
		else temp2[++c2]=a[i];
	}if(c1==r-l+1||c2==r-l+1)return;
	F(i,1,c1)a[l+i-1]=temp1[i];
	F(i,1,c2)a[l+c1+i-1]=temp2[i];
//	memcpy(a+l,temp1+1,c1<<2);
//	memcpy(a+l+c1,temp2+1,c2<<2);
	ri qwq=c1;dfs(l,l+c1-1);dfs(l+qwq,r);
}
int main() {
	cin>>t;
	while(t--) {
		cin>>n>>q;
		F(i,1,n)read(a[i]);
		memset(can,0,sizeof(can));cnt=0;
		dfs(1,n);
		sort(can+1,can+cnt+1);
		while(q--){
			if(binary_search(can+1,can+cnt+1,read()))puts("Yes");
			else puts("No");
		}
	}
	return 0;
}