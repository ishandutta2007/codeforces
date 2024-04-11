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
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
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
int ch[200002][26],cnt,n,m,p[200002],qwq,fa[200002],q[200002],l,r,tot,sz[200002],sum[200002],dfn[200002];
char temp[200002];
string s[200002];
vector<int>c[200002];
inline void ins(const string &s){
	int now=0;
	for(char i:s){
		if(ch[now][i-'a'])now=ch[now][i-'a'];
		else now=ch[now][i-'a']=++cnt;
	}
	p[++qwq]=now;
}
inline void getfail(){
	while(l<=r){
		int pos=q[l++];
		F(i,0,25){
			if(ch[pos][i]){
				if(pos)fa[ch[pos][i]]=ch[fa[pos]][i];
				q[++r]=ch[pos][i];
			}else ch[pos][i]=ch[fa[pos]][i];
		}
	}
}
inline void dfs(int pos){
	sz[pos]=1;
	dfn[pos]=++tot;
	for(int i:c[pos]){
		dfs(i);
		sz[pos]+=sz[i];
	}
}
inline void add(int pos){
	pos=dfn[pos];
	while(pos<=tot)++sum[pos],pos+=(-pos&pos);
}
inline int query_(int pos){
	int rt=0;
	while(pos)rt+=sum[pos],pos-=(-pos&pos);
	return rt;
}
inline int query(int pos){
	return query_(dfn[pos]+sz[pos]-1)-query_(dfn[pos]-1);
}
inline void play(string s){
	int now=0;
	for(int i:s){
		now=ch[now][i-'a'];
		add(now);
	}
}
vector<pii>qr[200002];
int ans[500002];
int main(){
	cin>>n>>m;
	F(i,1,n){
		scanf("%s",temp);
		s[i]=temp;
		ins(s[i]);
	}
	getfail();
	F(i,1,cnt)c[fa[i]].push_back(i);
	dfs(0);
	F(i,1,m){
		int l=read(),r=read(),k=read();
		qr[l-1].push_back(make_pair(k,-i));
		qr[r].push_back(make_pair(k,i));
	}
	F(i,1,n){
		play(s[i]);
		for(pii j:qr[i]){
			if(j.second>0)ans[j.second]+=query(p[j.first]);
			else ans[-j.second]-=query(p[j.first]);
		}
	}
	F(i,1,m)write(ans[i],'\n');
    return 0;
}