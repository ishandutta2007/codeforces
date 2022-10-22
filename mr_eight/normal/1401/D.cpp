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
//#pragma GCC optimize(3)
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
ll t,n,t1,t2,f[100002],m,p[100002],size[100002],v[100002],ans;
vector<int>g[100002],c[100002];
bool vis[100002];
inline void make_tree(int pos) {
	vis[pos]=1;
	ri nxt;
	F(i,0,g[pos].size()-1) {
		nxt=g[pos][i];
		if(!vis[nxt]) {
			f[nxt]=pos;
			c[pos].push_back(nxt);
			make_tree(nxt);
		}
	}
}
inline void dfs(int pos) {
	F(i,0,c[pos].size()-1) {
		dfs(c[pos][i]);
		size[pos]+=size[c[pos][i]];
	}
}
int main() {
	cin>>t;
	while(t--) {
		cin>>n;
		F(i,1,n)f[i]=0,g[i].clear(),c[i].clear(),vis[i]=0,size[i]=1;
		F(i,2,n) {
			t1=read(),t2=read();
			g[t1].push_back(t2);
			g[t2].push_back(t1);
		}
		make_tree(1);
		dfs(1);
		F(i,2,n)v[i-1]=size[i]*(n-size[i]);
		cin>>m;
		F(i,1,m)p[i]=read();
		if(m<n) {


			while(m<n-1)p[++m]=1;
			sort(v+1,v+n);
			sort(p+1,p+n);
			ans=0;
			F(i,1,n-1) {
				ans+=p[i]*v[i];
				ans%=1000000007;
			}
			cout<<ans<<endl;
		} else {sort(p+1,p+m+1);
			F(i,n,m) {
				p[n-1]*=p[i];
				p[n-1]%=1000000007;
			}
			sort(v+1,v+n);
			ans=0;
			F(i,1,n-1) {
				ans+=p[i]*v[i];
				ans%=1000000007;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}