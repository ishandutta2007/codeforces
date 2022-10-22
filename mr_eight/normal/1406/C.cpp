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
int n,t1,t2,size[200002],f[200002],t,a,b;
vector<int>g[200002],c[200002];
bool vis[200002];
void make_tree(int pos) {
	vis[pos]=1;size[pos]=1;
	ri nxt;
	F(i,0,g[pos].size()-1) {
		nxt=g[pos][i];
		if(!vis[nxt]) {
			f[nxt]=pos;
			c[pos].push_back(nxt);
			make_tree(nxt);
			size[pos]+=size[nxt];
		}
	}
}
inline void dfs(int pos){
	F(i,0,c[pos].size()-1){
		dfs(c[pos][i]);
	}ri mmax=0;
	F(i,0,c[pos].size()-1)mmax=max(mmax,size[c[pos][i]]);
	mmax=max(mmax,size[1]-size[pos]);
	if(mmax<=n/2){
		if(a)b=pos;
		else a=pos;
	}
}
inline void findb(int pos){
	if(c[pos].size())findb(c[pos][0]);
	else{
		cout<<pos<<' '<<f[pos]<<endl;
		cout<<b<<' '<<pos<<endl;
	}
}inline void finda(int pos){
	if(c[pos].size())finda(c[pos][0]);
	else{
		cout<<pos<<' '<<f[pos]<<endl;
		cout<<a<<' '<<pos<<endl;
	}
}
int main() {
	cin>>t;
	while(t--) {
		a=b=0;
		cin>>n;
		F(i,1,n) {vis[i]=0;
			g[i].clear();
			c[i].clear();
			f[i]=0;
		}
		F(i,2,n) {
			t1=read(),t2=read();
			g[t1].push_back(t2);
			g[t2].push_back(t1);
		}
		make_tree(1);
		dfs(1);
		if(b==0){
			cout<<a<<' '<<c[a][0]<<endl;
			cout<<a<<' '<<c[a][0]<<endl;
		}else{
			if(f[a]==b){
				findb(a);
			}else{
				finda(b);
			}
		}
	}
	return 0;
}