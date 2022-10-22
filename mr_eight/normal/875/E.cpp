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
	while((c=getchar())==' '||c=='\n');
	return c;
}
int n,s1,s2,a[100002],l,r,mid;
set<int>p;
set<int>::iterator d,nxt;
bool check(int num) {
	p.clear();
	p.insert(s2);
	F(i,1,n) {
		while(!p.empty()&&abs(*p.begin()-a[i])>num)p.erase(p.begin());
		if(!p.empty()) {
			d=p.end(),d--;
			while(!p.empty()&&abs((*d)-a[i])>num) {
				nxt=d;
				d--;
				p.erase(nxt);
			}
		}
		if(abs(a[i]-a[i-1])<=num)p.insert(a[i-1]);
		if(p.empty())return 0;
	}
	return 1;
}
int main() {
	cin>>n>>s1>>s2;
	a[0]=s1;
	F(i,1,n)a[i]=read();
	l=abs(s1-s2),r=1000000000;
	while(l<r) {
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l;
	return 0;
}