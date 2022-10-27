#include <string.h>
#include <unordered_map>
 
#include <sstream>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <iostream>
#include   <stdlib.h>    
#include   <time.h> 
#include <stack>
#include <queue>
#include <set>
 
#include <map>
#include <vector>
#include <string>
#include <stdlib.h>
 
#define ll long long
#define clr(x) memset(x,0,sizeof(x))
#define _clr(x) memset(x,-1,sizeof(x))
#define fr(i,a,b) for(int i = a; i < b; ++i)
#define frr(i,a,b) for(int i = a; i > b; --i)
#define pb push_back
#define sf scanf
 
#define pf printf
#define mp make_pair
 
using namespace std;
const int N = 1100000;
int mod = 998244353;
 
int n;
ll k;
string s,t;
 
struct Info{
	int l,r;
	int flag;
	Info():l(0),r(0),flag(0){}
	Info(int l, int r, int flag):l(l),r(r),flag(flag){}
}info[1000010];
 
vector<int> g[1000010];
int st[1000010],dep[1000010],in[1000010],out[1000010],cnt;
int p[1000010];
int rmq[500010][30];
 
void dfs(int t, int f) {
	st[cnt]=t;
	dep[t] = dep[f]+1;
	in[t]=cnt++;
 
	for(int u : g[t]) {
		if(u==f)continue;
		dfs(u,t);
		st[cnt++]=t;
	}
	out[t] = cnt;
}
 
void init_rmq() {
	for(int i = 0; i < cnt; ++i) {
		rmq[i][0] = st[i];
	}
 
	for(int i = 1; (1<<i) <=cnt; ++i) {
		for(int j = 0; j < cnt&&(j+(1<<i))<cnt; ++j) {
			rmq[j][i] = dep[rmq[j][i-1]] < dep[rmq[j+(1<<(i-1))][i-1]]? rmq[j][i-1]:rmq[j+(1<<(i-1))][i-1];
		}
	}
}
 
int lca(int a, int b) {
	if(in[a]>in[b]) {
		swap(a,b);
	}
 
	int l = in[a],r = in[b];
	int k = 0;
	while((1<<k)<=(r-l+1))k++;
	k--;
	int t1 = rmq[l][k];
	int t2 = rmq[r-(1<<k)+1][k];
	return dep[t1]>dep[t2]? t2:t1;
}
 
int check_in(int x, int a, int b) {
	if(dep[a]<dep[b]) swap(a,b);
	int t1 = lca(x,a);
	int t2 = lca(x,b);
	return t1==x&&t2==b;
}
 
int res=-1;
Info res_info;
 
Info merge(Info a, Info b) {
	Info c;
	if(!a.flag || !b.flag) {
		c.flag = 0;
		return c;
	}
	if(in[a.l]>in[b.l]) {
		swap(a,b);
	}
	int t1 = lca(a.l,a.r);
	int t2 = lca(b.l,b.r);
 
	if(t1==a.l&&t2==b.l) {
		if(lca(b.l,a.r)==a.r) {
			c.flag = 1;
			c.l = a.l;
			c.r = b.r;
			if(in[c.l]>in[c.r]) swap(c.l,c.r);
		}
		else {
			int ttf = lca(b.l,a.r);
			if(ttf == a.l || lca(a.l,b.l)!=a.l) {
				c.flag = 1;
				c.l = a.r;
				c.r = b.r;
				if(in[c.l]>in[c.r]) swap(c.l,c.r);
			}
			else if(check_in(b.l,a.l,a.r)) {
				if(check_in(b.r,a.l,a.r)) {
					c.flag = 1;
					c.l = a.l;
					c.r = a.r;
				}
				else if(check_in(a.r,a.l,b.r)) {
					c.flag = 1;
					c.l = a.l;
					c.r = b.r;
				}
			}
		}
	}
	else if(t1==a.l){
		int tf = lca(b.l,b.r);
		if(t1==tf) {
			if(check_in(a.r,b.l,tf)) {
				c.flag = 1;
				c.l = b.l;
				c.r = b.r;
			}
			else if(check_in(b.l,a.r,tf)){
				c.flag = 1;
				c.l = a.r;
				c.r = b.r;
			}
			else if(check_in(a.r,b.r,tf)) {
				c.flag = 1;
				c.l = b.l;
				c.r = b.r;
			}
			else if(check_in(b.r,a.r,tf)) {
				c.flag = 1;
				c.l = b.l;
				c.r = a.r;
			}
		}
		else{
			if(check_in(a.l,tf,b.l)) {
				if(check_in(a.r,tf,b.l)){
					c.flag = 1;
					c.l = b.l;
					c.r = b.r;
				}
				else if(check_in(b.l,tf,a.r)){
					c.flag = 1;
					c.l = a.r;
					c.r = b.r;
				}
			}
			else if(check_in(a.l,tf,b.r)) {
				if(check_in(b.r,tf,a.r)){
					c.flag = 1;
					c.l = b.l;
					c.r = a.r;
				}
				else if(check_in(a.r,tf,b.r)){
					c.flag = 1;
					c.l = b.l;
					c.r = b.r;
				}
			}
		}
	}else if(t2==b.l) {
		int tf = lca(a.l,a.r);
		if(check_in(b.l, tf, a.r)){
			if(check_in(a.r,tf,b.r)){
				c.flag = 1;
				c.l = a.l;
				c.r = b.r;
			}
			else if(check_in(b.r,a.r,tf)){
				c.flag = 1;
				c.l = a.l;
				c.r = a.r;
			}
		}
		else if(check_in(b.l,a.r,b.r)) {
			c.flag = 1;
			c.l = a.l;
			c.r = b.r;
		}
		else if(check_in(b.l,a.l,b.r)) {
			c.flag = 1;
			c.l = b.r;
			c.r = a.r;
		}
	}
	else {
		int ta = lca(a.l,a.r);
		int tb = lca(b.l,b.r);
		if(ta==tb) {
			if(check_in(a.l, b.l, ta)||check_in(b.l,a.l,ta)){
				if(check_in(a.r,b.r,ta)||check_in(b.r,a.r,ta)) {
					c.flag = 1;
					c.l = dep[a.l]>dep[b.l]?a.l:b.l;
					c.r = dep[a.r]>dep[b.r]?a.r:b.r;
				}
			}
		}
	}
	return c;
}
 
int check(int t,int l, int r) {
 
	int f = lca(info[t].l, info[t].r);
	int num = dep[info[t].l] + dep[info[t].r] - 2*dep[f]+1;
	return num >= r-l+1;
}
 
void add(int t, int l, int r, int pos, int v) {
	if(l>r)return;
	if(l==r) {
		info[t] = Info(v,v,1);
		return;
	}
	int mid= (l+r)>>1;
	if(pos<=mid)add(t<<1,l,mid,pos,v);
	else add(t<<1|1,mid+1,r,pos,v);
	info[t] = merge(info[t<<1],info[t<<1|1]);
}
 
int query(int t, int l, int r) {
	if(info[t].flag) {
		if(check(t,l,r) ){
			if(res==-1) {
				res_info = info[t]; 
				res = r;
				return 1;
			}
			else {
				Info tmp = merge(res_info,info[t]);
				if(tmp.flag) {
					res_info = tmp;
					res = r;
					return 1;
				}
				else {
					if(l<r){
						int mid = (l+r)>>1;
						int ret = query(t<<1,l,mid);
						if(ret) {
							query(t<<1|1,mid+1,r);
						}
					}
					return 0;
				}
			}
		}
		else {
			int mid = (l+r)>>1;
			int t1 = query(t<<1,l,mid);
			if(t1)return query(t<<1|1,mid+1,r);
			return 0;
		}
	}
	int mid = (l+r)>>1;
	int ret = query(t<<1,l,mid);
	if(ret) {
		query(t<<1|1,mid+1,r);
	}
	return 0;
}
 
int main() {
	cin>>n;
	fr(i,0,n) sf("%d",&p[i+1]);
	fr(i,2,n+1) {
		int u;
		sf("%d",&u);
		g[u].pb(i);
	}
	clr(dep);
	cnt = 0;
	dfs(1,1);
	init_rmq();
	for(int i = 1; i <=n; ++i) {
		add(1,0,n-1,p[i],i);
	}
 
	int q;
	sf("%d",&q);
	while(q--) {
		int cmd;
		sf("%d",&cmd);
		if(cmd==1) {
			int u,v;
			sf("%d%d",&u,&v);
			swap(p[u],p[v]);
			add(1,0,n-1,p[u],u);
			add(1,0,n-1,p[v],v);
		}
		else {
			res = -1;
			query(1,0,n-1);
			cout<<res+1<<endl;
		}
	}
}