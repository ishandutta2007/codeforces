//#include <bits/c++config.h>
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
#define ll long long //long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
#define cp complex<double>
#define endl '\n'//
#pragma GCC optimize(3)
using namespace std;
using std::bitset;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
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
int n,m,l[2002][2002],d[2002][2002],u[2002][2002],ans[2002][2002],r[2002][2002],q[4002],ql,qr,L[2002][2002],rr[2002][2002];
char a[2002][2002];
inline void insert(int i,int j) {
	ri k=l[i][j]-i;
	while(ql<=qr&&k<=(l[q[qr]][j]-q[qr])) {
		qr--;
	}
	q[++qr]=i;
}
inline void insert2(int i,int j) {
	ri k=r[i][j]-i;
	while(ql<=qr&&k<=r[q[qr]][j]-q[qr]) {
		qr--;
	}
	q[++qr]=i;
}
inline void insert3(int i,int j) {
	ri k=l[i][j]+i;
	while(ql<=qr&&k<=(l[q[qr]][j]+q[qr])) {
		qr--;
	}
	q[++qr]=i;
}
inline void insert4(int i,int j) {
	ri k=r[i][j]+i;
	while(ql<=qr&&k<=r[q[qr]][j]+q[qr]) {
		qr--;
	}
	q[++qr]=i;
}

int main() {
	cin>>n>>m;
	F(i,1,n){getchar();
		F(j,1,m) {
		a[i][j]=getchar();
	}
	}
	F(i,1,n)F(j,1,m) {
		if(a[i][j]==a[i-1][j])u[i][j]=u[i-1][j]+1;
	}
	UF(i,n,1)F(j,1,m) {
		if(a[i][j]==a[i+1][j])d[i][j]=d[i+1][j]+1;
	}
	F(i,1,n)F(j,1,m) {
		if(a[i][j]==a[i][j-1])l[i][j]=l[i][j-1]+1;
	}
	F(i,1,n)UF(j,m,1) {
		if(a[i][j]==a[i][j+1])r[i][j]=r[i][j+1]+1;
	}
	F(j,1,m) {
		ql=1,qr=0;
		F(i,1,n) {
			ri k=l[i][j]-i;
	while(ql<=qr&&k<=(l[q[qr]][j]-q[qr])) {
		qr--;
	}
	q[++qr]=i;
			L[i][j]=q[ql];
		}
	}
	F(j,1,m) {
		ql=1,qr=0;
		F(i,1,n) {
			ri k=r[i][j]-i;
	while(ql<=qr&&k<=r[q[qr]][j]-q[qr]) {
		qr--;
	}
	q[++qr]=i;
			rr[i][j]=q[ql];
		}
	}
	F(i,1,n) {
		F(j,1,m) {
			ans[i][j]=min(l[L[i][j]][j]-L[i][j]+i+1,r[rr[i][j]][j]-rr[i][j]+i+1);
		}
	}
	F(j,1,m) {
		ql=1,qr=0;
		UF(i,n,1) {
			ri k=l[i][j]+i;
	while(ql<=qr&&k<=(l[q[qr]][j]+q[qr])) {
		qr--;
	}
	q[++qr]=i;
			L[i][j]=q[ql];
		}
	}
	F(j,1,m) {
		ql=1,qr=0;
		UF(i,n,1) {
			ri k=r[i][j]+i;
	while(ql<=qr&&k<=r[q[qr]][j]+q[qr]) {
		qr--;
	}
	q[++qr]=i;
			rr[i][j]=q[ql];
		}
	}
	F(i,1,n) {
		F(j,1,m) {
			ans[i][j]=min(ans[i][j],min(l[L[i][j]][j]+L[i][j]-i+1,r[rr[i][j]][j]+rr[i][j]-i+1));
		}
	}
	long long res=0;
	F(i,1,n) {
		F(j,1,m) {
			res+=min(ans[i][j],min(u[i][j]+1,d[i][j]+1));
		}
	}
	cout<<res;
	return 0;
}