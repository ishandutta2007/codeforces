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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define endl '\n'//
//#pragma GCC optimize(3)
using namespace std;
using std::bitset;
using namespace __gnu_pbds;
inline int read() {
	int x=0;
	bool fu=0;
	char ch=0;
	while(ch>'9'||ch<'0') {
		ch=getchar();
		if(ch=='-')fu=1;
	}
	while(ch<='9'&&ch>='0') x=(x*10+ch-48),ch=getchar();
	return fu?-x:x;
}
ll n,m,t1,t2,f[200002],T,v[200002],h[200002],size[200002],ok[200002];
vector<int>g[200002],c[200002];
bool vis[200002],ans;
void make_tree(int pos) {
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
void dfs(int pos) {
	size[pos]=v[pos];
	F(i,0,c[pos].size()-1) {
		dfs(c[pos][i]);
		size[pos]+=size[c[pos][i]];
	}
	if(size[pos]%2==0) {
		if((h[pos]+1000000000)%2==1) {
			ans=0;
		} else {
			ok[pos]=(h[pos]+size[pos])/2;
		}
	} else {
		if((h[pos]+1000000000)%2==0) {
			ans=0;
		} else {
			ok[pos]=(h[pos]+size[pos])/2;
		}
	}
	if(ok[pos]>size[pos]||ok[pos]<0)ans=0;

}
void d(int pos) {
	F(i,0,c[pos].size()-1) {
		d(c[pos][i]);
	}
	long long sum=0;
	F(i,0,c[pos].size()-1) {
		sum+=ok[c[pos][i]];
	}
	if(sum>ok[pos]) {
		ans=0;
	}
}
int main() {
	cin>>T;
	while(T--) {
		ans=1;
		cin>>n>>m;
		F(i,1,n) {
			v[i]=read();
			g[i].clear();
			c[i].clear();
			vis[i]=0;
			f[i]=0;
		}
		F(i,1,n) {
			h[i]=read();
		}
		F(i,2,n) {
			t1=read(),t2=read();
			g[t1].push_back(t2);
			g[t2].push_back(t1);
		}
		make_tree(1);
		dfs(1);
		d(1);
		if(ans) {
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
	}
	return 0;
}