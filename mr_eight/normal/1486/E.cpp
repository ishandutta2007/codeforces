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
#pragma GCC optimize(3)
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
int n,m,in[100002][52],cnt,t1,t2,t3;
vector<int>f[100002],w[100002];
ll dis[5100002];
int g[23000002],c[23000002],nxt[23000002],head[5100002],num;
bool vis[5100002];
struct s{
	int pos,dis;
	bool operator<(const s &b)const{
		return (dis==b.dis)?pos<b.pos:dis<b.dis;
	}bool operator>(const s &b)const{
		return (dis==b.dis)?pos>b.pos:dis>b.dis;
	}
};
priority_queue<s,vector<s>,greater<s> >q;
/*
inline void spfa(){
	dis[1]=0;
	l=r=1;
	q[1]=1;
	vis[1]=1;
	while(l!=r+1){
		ri pos=q[l++];
		if(l==5100000)l=0;
		for(ri i=head[pos];i;i=nxt[i]){
			if(dis[g[i]]>dis[pos]+c[i]){
				dis[g[i]]=dis[pos]+c[i];
				if(!vis[g[i]]){
					vis[g[i]]=1;
					++r;
					if(r==5100000)r=0;
					q[r]=g[i];
				}
			}
		}
		vis[pos]=0;
	}
}*/
int main() {
	memset(dis,0x3f,sizeof(dis));
	cin>>n>>m;cnt=n;
	F(i,1,m){
		read(t1);read(t2);read(t3);
		f[t1].push_back(t2);
		f[t2].push_back(t1);
		w[t1].push_back(t3);
		w[t2].push_back(t3);
		if(!in[t1][t3]){
			in[t1][t3]=++cnt;
		}
		g[++num]=in[t1][t3];
		nxt[num]=head[t2];
		head[t2]=num;
		swap(t1,t2);
		if(!in[t1][t3]){
			in[t1][t3]=++cnt;
		}
		g[++num]=in[t1][t3];
		nxt[num]=head[t2];
		head[t2]=num;
	}
	F(i,1,n){
		F(j,0,f[i].size()-1){
			F(k,1,50){
				if(in[i][k]){
					g[++num]=f[i][j];
					nxt[num]=head[in[i][k]];
					head[in[i][k]]=num;
					c[num]=(w[i][j]+k)*(w[i][j]+k);
				}
			}
		}
	}
	dis[1]=0;
	q.push((s){
		1,0
	});
	while(!q.empty()){
		ri pos=q.top().pos;
		q.pop();
		if(vis[pos])continue;
		vis[pos]=1;
		for(ri i=head[pos];i;i=nxt[i]){
			if(dis[g[i]]>dis[pos]+c[i]){
				dis[g[i]]=dis[pos]+c[i];
				q.push((s){g[i],dis[g[i]]});
			}
		}
	}
	F(i,1,n){
		if(dis[i]>1e14)write(-1,' ');
		else write(dis[i],' ');
	}
	return 0;
}