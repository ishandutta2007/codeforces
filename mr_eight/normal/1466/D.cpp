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
const int MAXN=100002;
int n,t1,t2,f[MAXN],num[MAXN],temp[100002],w[MAXN];
vector<int>g[MAXN],c[MAXN];
bool vis[MAXN];
long long ans;
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
inline bool cmp(int x,int y){
	return w[x]>w[y];
}
char _n_u_m_[40];
	template<class T>
	inline void write(T x ) {
		if(x==0) {
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		register int cnt = 0 ;
		while( tmp > 0 ) {
			_n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
	}
	template<class T>
	inline void write(T x ,char ch) {
		write(x);
		putchar(ch);
	}
void play(){
	write(ans,' ');
	ri now=1;
	F(i,1,n-2){
		while(num[temp[now]]==0)now++;
		ans+=w[temp[now]];
		num[temp[now]]--;
		write(ans,' ');
	}putchar('\n');
}
int main() {
	F(orz,1,read()) {ans=0;
		cin>>n;
		F(i,1,n)w[i]=read(),ans+=w[i];
		F(i,2,n) {
			t1=read(),t2=read();
			num[t1]++,num[t2]++;
		}
		F(i,1,n)temp[i]=i,num[i]--;
		sort(temp+1,temp+n+1,cmp);
		temp[n+1]=n+1;
		w[n+1]=0;
		num[n+1]=INT_MAX;
		play();
	}

	return 0;
}