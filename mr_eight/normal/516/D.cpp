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
namespace fastIO {
	template<class T>
	inline void read(T &x) {
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
	char _n_u_m_[40];
	template<class T>
	inline void write(T x ) {
		if(x==0){
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
}
using namespace fastIO;
const int MAXN=100002;
int n,t1,t2,f[MAXN],S,T;ll dis1[MAXN],dis2[MAXN];int root,ans[MAXN];
vector<int>g[MAXN],c[MAXN];
vector<int>co[MAXN];ll l;
bool vis[MAXN];
#define dis dis1
inline void make_tree(int pos){
	vis[pos]=1;ri nxt;
	F(i,0,g[pos].size()-1){
		nxt=g[pos][i];
		if(!vis[nxt]){
			f[nxt]=pos;
			c[pos].push_back(nxt);
			make_tree(nxt);
		}
	}
}
inline void dfs(int pos,ll *temp,int fa){
	F(i,0,g[pos].size()-1){
		if(g[pos][i]!=fa){
			temp[g[pos][i]]=temp[pos]+co[pos][i];
			dfs(g[pos][i],temp,pos);
		}
	}
}
vector<int>ak;
vector<ll>d;
inline void play(int pos){
	ak.push_back(pos);
	d.push_back(dis[pos]);
	++ans[pos];
	--ans[f[ak[lower_bound(d.begin(),d.end(),dis[pos]-l)-d.begin()]]];
	for(auto i:c[pos])play(i);
	ak.pop_back();
	d.pop_back();
}
inline void orz(int pos){
	for(auto i:c[pos]){
		orz(i);
		ans[pos]+=ans[i];
	}
}
int main(){
    cin>>n;//d.push_back(-LLONG_MAX);ak.push_back(0);
    F(i,2,n){
    	t1=read(),t2=read();ll t3=read();
    	g[t1].push_back(t2);
    	g[t2].push_back(t1);
    	co[t1].push_back(t3);
    	co[t2].push_back(t3);
	}
	dfs(1,dis1,0);
	S=max_element(dis1+1,dis1+n+1)-dis1;
	dis1[S]=0;
	dfs(S,dis1,0);
	T=max_element(dis1+1,dis1+n+1)-dis1;
	dfs(T,dis2,0);
	dis1[0]=LLONG_MAX;
	F(i,1,n){
		if(max(dis1[i],dis2[i])<max(dis1[root],dis2[root]))root=i;
		dis[i]=max(dis1[i],dis2[i]);
	}
	make_tree(root);
	F(iakioi,1,read()){
		memset(ans,0,sizeof(ans));
		read(l);
		play(root);
		orz(root);
		write(*max_element(ans+1,ans+n+1),'\n');
	}
    return 0;
}