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
#pragma GCC optimize(3)
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
int n,t1,t2,k,T,l[200002],ans,cnt;
vector<int>g[200002];
queue<int>q;
bool vis[200002];
void go(int pos) {
	F(i,0,g[pos].size()-1) {
		if(g[g[pos][i]].size()==1)l[pos]++;
	}
}
signed main() {
	cin>>T;
	F(aoligei,1,T) {
		F(i,1,n) {
			vis[i]=0;
			l[i]=0;
		}
		F(i,1,n) {
			g[i].clear();
		}
		cin>>n>>k;

		F(i,2,n) {
			t1=read(),t2=read();
			g[t1].push_back(t2);
			g[t2].push_back(t1);
		}
		if(k==1) {
cout<<n-1<<endl;
			continue;
		}
		F(i,1,n)go(i);
		F(i,1,n) {
			if(l[i]>=k)q.push(i);
		}
		ri h;
		ans=0;
//	F(i,1,n)cout<<l[i]<<' ';
		while(!q.empty()) {//cout<<q.front()<<' ';
			h=q.front();
			ans+=l[h]/k;
			for(ri i=0,cnt=1; cnt<=l[h]-(l[h]%k); cnt++,i++) { //cout<<'v';
				if(i>=g[h].size())break;
				if(g[g[h][i]].size()==1) {
					g[h].erase(g[h].begin()+i);
					i--;
				} else {
					cnt--;
				}
			}
			l[h]%=k;
			if(g[h].size()==1) {
				l[g[h][0]]++;
				if(l[g[h][0]]==k) {
					q.push(g[h][0]);
				}
			}
			q.pop();
		}
cout<<ans<<endl;
	}
	return 0;
}