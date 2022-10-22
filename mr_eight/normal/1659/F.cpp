//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
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
#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
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
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
using namespace std;
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
	inline void write(T x) {
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
}
using namespace fastIO;
struct S {
	basic_string<int>v;
};
basic_string<int>p;
int n,x;
vector<int>g[200002];
int c[200002];
inline void add(int pos) {
	while(pos<=n) {
		++c[pos];
		pos+=(-pos&pos);
	}
}
inline int query(int pos) {
	int rt=0;
	while(pos) {
		rt+=c[pos];
		pos-=(-pos&pos);
	}
	return rt;
}
map<basic_string<int>,bool>vis;
map<basic_string<int>,int>w[12][12];
queue<basic_string<int> >q;
inline void solve(auto p) {
	while(!q.empty())q.pop();
	F(i,1,11)F(j,i+1,11)w[i][j].clear();
	vis.clear();
	basic_string<int>temp;
	temp.resize(n+1);
	F(i,1,n)temp[i]=i;
	F(i,1,n)temp[0]=i,q.push(temp),vis[temp]=true;
	while(!q.empty()) {
		auto v=q.front();
		q.pop();//F(i,0,n)cerr<<v[i]<<" ";cerr<<endl;
		if(v==p) {
			puts("Alice");
			return;
		}
		int qwq=v[0];
		F(x,1,n-1)F(y,x+1,n) {
			swap(v[x],v[y]);
			for(int z:g[qwq])if(v[x]!=z&&v[y]!=z) {
					v[0]=z;
					if(!vis[v]) {
						++w[x][y][v];
						if(w[x][y][v]==g[z].size()) {
							q.push(v);
							vis[v]=true;
						}
					}

				}
			swap(v[x],v[y]);
		}
		v[0]=qwq;
	}
	puts("Bob");
}
inline bool check(){
	int cnt=0;
	F(i,1,n)if(p[i]!=i)++cnt;
	return cnt==2;
}
int main() {
	F(iakioi,1,read()) {
		read(n);
		read(x);
		F(i,1,n)g[i].clear();
		F(i,2,n) {
			int t1=read(),t2=read();
			g[t1].push_back(t2);
			g[t2].push_back(t1);
		}
		p.resize(n+1);
		F(i,1,n)read(p[i]);
		p[0]=x;
		int pos=0;
		F(i,1,n)if(g[i].size()>g[pos].size())pos=i;
		if(g[pos].size()<n-1&&n>=6) {
			puts("Alice");
		} else if(n<6) {
			solve(p);
		} else {
			F(i,1,n)c[i]=0;
			ll rt=0;
			UF(i,n,1) {
				rt+=query(p[i]);
				add(p[i]);
			}
			if(rt==0) {
				puts("Alice");
			} else if(check()) {
				int t1=0,t2=0;
				F(j,1,n)if(p[j]!=j) {
					if(t1)t2=j;
					else t1=j;
				}
				if(x==t1||x==t2)puts("Bob");
				else puts("Alice");
			} else {
				if(p[pos]!=pos&&(x==pos||x==p[pos])){
					puts("Bob");
				}else {
					if((x==pos)^(rt&1))puts("Bob");
					else puts("Alice");
				}
			}
		//	solve(p);
		}
	}
	return 0;
}
/*
7 1
1 2 1 3 1 4 1 5 1 6 1 7
1 2 4 3 7 6 5
*/