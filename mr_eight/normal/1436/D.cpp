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
ll n,p[200002],size[200002],ans,num[200002],dp[200002];
vector<int>c[200002];
inline ll dfs(int pos) {
	size[pos]=p[pos];
	F(i,0,c[pos].size()-1)size[pos]+=dfs(c[pos][i]);
	return size[pos];
}
inline ll dfs2(int pos) {
	if(c[pos].empty()) {
		num[pos]=1;
	} else {
		F(i,0,c[pos].size()-1) {
			num[pos]+=dfs2(c[pos][i]);
		}
	}
	return num[pos];
}
int main() {
	cin>>n;
	F(i,2,n)c[read()].push_back(i);
	F(i,1,n)p[i]=read();
	dfs(1);
	dfs2(1);
	F(i,1,n) {
		if(c[i].empty()) {
			dp[i]=p[i];
			ans=max(ans,p[i]);
			continue;
		}
		ll mmax=0,sum=size[i];
		dp[i]=ceil((double(sum))/num[i]);ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}