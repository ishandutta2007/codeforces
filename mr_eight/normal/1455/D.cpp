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
template<class T>
inline T read(T &x) {
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
int f[505][505],g[505][505],a[505],n,t,x,ans;
int main() {
	cin>>t;
	while(t--) {
		memset(f,0x3f,sizeof(f));
		memset(g,0x3f,sizeof(g));
		ans=INT_MAX;
		cin>>n>>x;x++;
		F(i,1,n)read(a[i]),a[i]++;
		f[1][x]=0;
		g[1][x]=1;
		F(i,1,n) {
			F(j,1,501) {
				if (a[i]>=a[i-1]) {
					f[i][j]=min(f[i][j],f[i-1][j]);
				}
				if(j==a[i-1]) {
					F(k,1,min(a[i-1],a[i])) {
						f[i][j]=min(f[i][j],g[i-1][k]);
					}
				}
				if(j<=a[i]) {
					if(j>=a[i-1])g[i][j]=min(g[i][j],f[i-1][j]+1);
					if(j==a[i-1])
						F(k,1,j) {
						g[i][j]=min(g[i][j],g[i-1][k]+1);
					}
				}
				}
			}
		
		F(j,1,501) {
			ans=min(ans,f[n][j]);
			ans=min(ans,g[n][j]);
		}
		if(ans<1e9)cout<<ans<<'\n';
		else cout<<-1<<'\n';
	}
	return 0;
}