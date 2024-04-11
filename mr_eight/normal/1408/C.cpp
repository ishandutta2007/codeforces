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
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
#define low(x) (-x&x)
#define cp complex<double>
//#pra gma G CC opti mize(3)
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
inline char readc() {
	register char c;
	while((c=getchar())>='Z'||c<='A');
	return c;
}
double t,n,l,nowt,a,b,q[100002],x,y;
int p1,p2;
int main() {
	cin>>t;
	while(t--) {
		cin>>n>>l;
		F(i,1,n) {
			q[i]=read();
		}
		nowt=0,a=0,b=l,x=1,y=1,p1=0,p2=n+1;
		while(p2-p1>1) {
			if((q[p1+1]-a)/x==(-q[p2-1]+b)/y) {
				nowt+=(q[p1+1]-a)/x;
				x++;
				y++;
				p1++,p2--;
				a=q[p1],b=q[p2];
			} else if((q[p1+1]-a)/x<(-q[p2-1]+b)/y) {
				nowt+=(q[p1+1]-a)/x;
				
				p1++;
				b-=(q[p1]-a)/x*y,a=q[p1];x++;
			} else {
				nowt+=(-q[p2-1]+b)/y;
				
				p2--;
				a+=(b-q[p2])/y*x,b=q[p2];y++;
			}
		}
		cout<<fixed<<setprecision(10)<<nowt+(b-a)/(x+y)<<endl;
	}
	return 0;
}