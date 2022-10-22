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
int T,n;
string s1,s2;
int main() {
	cin>>T;
	while(T--) {int ans=0;bool x=0;
		cin>>n>>s1>>s2;

		F(i,0,n-1)if(s1[i]>s2[i]) {
			cout<<-1<<endl;
			x=1;
			break;
		}if(x)continue;
		F(i,'a','y') {
			int mmin=1000;
			F(j,0,n-1) {
				if(s1[j]==i) {
					if(s2[j]!=i)mmin=min((int)s2[j],mmin);
				}
			}
			if(mmin<1000) {ans++;
				F(j,0,n-1) {
					if(s1[j]==i) {
						if(s2[j]!=i)s1[j]=mmin;
					}
				}
			}
		}cout<<ans<<endl;
	}
	return 0;
}