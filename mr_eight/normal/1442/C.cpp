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
struct s {
	int pos;
	ll dis;
	inline bool operator>(const s &b)const {
		return dis>b.dis;
	}
};
int n,m,t1,t2;
ll dis[400002],d[400002][22],ans=LLONG_MAX;
vector<int>g[400002];
bool vis[400002],v[400002][22];
deque<int>q;
deque<pair<int,int> >q2;
queue<int>q3;
priority_queue<s,vector<s>,greater<s> >qwq;
void bfs() {
	register int pos;
	q.push_back(1);
	vis[1]=1;
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	while(!q.empty()) {
		pos=q.front();
		q.pop_front();
		if(pos<=n) {
			if(!vis[pos+n]) {
				vis[pos+n]=1;
				dis[pos+n]=dis[pos]+1;
				q.push_back(pos+n);
			}
		} else {
			if(!vis[pos-n]) {
				vis[pos-n]=1;
				dis[pos-n]=dis[pos]+1;
				q.push_back(pos-n);
			}
		}
		F(i,0,g[pos].size()-1) {
			if(!vis[g[pos][i]]) {
				vis[g[pos][i]]=1;
				dis[g[pos][i]]=dis[pos];
				q.push_front(g[pos][i]);
			}
		}
	}//cout<<dis[n]<<' '<<dis[2*n];
}
void spfa() {
	q2.push_back(make_pair(1,0));
	v[1][0]=1;
	memset(d,0x3f,sizeof(d));
	d[1][0]=0;
	ri pos,k;
	while(!q2.empty()) {
		pos=q2.front().first,k=q2.front().second;
		q2.pop_front();
		if(k<=19) {
			if(pos<=n) {
				if(!v[pos+n][k+1]) {
					d[pos+n][k+1]=d[pos][k];
					if(!v[pos+n][k+1]) {
						v[pos+n][k+1]=1;
						q2.push_front(make_pair(pos+n,k+1));
					}
				}
			} else {
				if(!v[pos-n][k+1]) {
					d[pos-n][k+1]=d[pos][k];
					if(!v[pos-n][k+1]) {
						v[pos-n][k+1]=1;
						q2.push_front(make_pair(pos-n,k+1));
					}
				}
			}
		}
		F(i,0,g[pos].size()-1) {
			if(!v[g[pos][i]][k]) {
				d[g[pos][i]][k]=d[pos][k]+1;
				if(!v[g[pos][i]][k]) {
					v[g[pos][i]][k]=1;
					q2.push_back(make_pair(g[pos][i],k));
				}
			}
		}
	}
	F(i,0,20)d[n][i]+=(1<<i)-1,d[n+n][i]+=(1<<i)-1;
}
#define q2 q3
#define d dis
#define v vis/*
 
void spfa2() {
	q2.push(1);
	v[1]=1;
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	ri pos,k;
	while(!q2.empty()) {
		pos=q2.front();
		q2.pop();
		v[pos]=0;
		if(pos<=n) {
			if(d[pos+n]>d[pos]+INT_MAX) {
				d[pos+n]=d[pos]+INT_MAX;
				if(!v[pos+n]) {
					v[pos+n]=1;
					q2.push(pos+n);
				}
			}
		} else {
			if(d[pos-n]>d[pos]+INT_MAX) {
				d[pos-n]=d[pos]+INT_MAX;
				if(!v[pos-n]) {
					v[pos-n]=1;
					q2.push(pos-n);
				}
			}
		}
		F(i,0,g[pos].size()-1) {
			if(d[g[pos][i]]>d[pos]+1) {
				d[g[pos][i]]=d[pos]+1;
				if(!v[g[pos][i]]) {
					v[g[pos][i]]=1;
					q2.push(g[pos][i]);
				}
			}
		}
	}
}*/

void spfa2() {
	ri pos;
	memset(vis,0,sizeof(vis));
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	qwq.push((s) {
		1,0ll
	});
	while(!qwq.empty()) {
		pos=qwq.top().pos;
		qwq.pop();
		if(vis[pos])continue;
		vis[pos]=1;
		if(pos<=n) {
			if(d[pos+n]>d[pos]+INT_MAX) {
				d[pos+n]=d[pos]+INT_MAX;
				qwq.push((s) {
					pos+n,d[pos+n]
				});
			}
		} else {
			if(d[pos-n]>d[pos]+INT_MAX) {
				d[pos-n]=d[pos]+INT_MAX;
				qwq.push((s) {
					pos-n,d[pos-n]
				});
			}
		}
		F(i,0,g[pos].size()-1) {
			if(d[g[pos][i]]>d[pos]+1) {
				d[g[pos][i]]=d[pos]+1;
				qwq.push((s) {
					g[pos][i],d[pos]+1
				});
			}
		}
	}
}
#undef q2
#undef d
#undef v
bool tagg;
int main() {
	cin>>n>>m;
	F(i,1,m) {
		t1=read(),t2=read();if(i==1&&t1==67237)tagg=1;
		g[t1].push_back(t2);
		g[t2+n].push_back(t1+n);
	}
	bfs();
	if(min(dis[n],dis[2*n])<=20) {
	
		spfa();
		F(i,0,20) {
			ans=min(ans,d[n][i]);
			ans=min(ans,d[n+n][i]);
		}
		cout<<ans%998244353;
		return 0;
	} else {
		spfa2();
		if(dis[n]>dis[n+n])dis[n]=dis[n+n];
		m=dis[n]/INT_MAX;
		dis[n]%=INT_MAX;
		ans=1;
		while(m--) {
			ans*=2;
			ans%=998244353;
		}
		ans--;
		ans+=dis[n];
		cout<<ans%998244353;
	}
	return 0;
}