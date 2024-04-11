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
#define ll long long //long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define openf(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define re register
#define ri re int
#define il inline
#define cp complex<double>
#define endl '\n'//
//#pragma GCC optimize(3)
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
}ll n,m,q,t1,t2,t3,t4,f1[200002],a[800002],tag[800002],x1[200002],x2[200002],
f2[200002],o[200002],dis[200002],dis2[200002],cnt=1,num[200002];
struct edge{
	ll u,v,w;
	bool two;
}ed[200002];
struct edgex{
	ll u,v,w;
	bool operator<(const edgex &b)const{
		return (u==b.u)?((v==b.v)?(w>b.w):(v>b.v)):(u>b.u);
	}
};
vector<ll>g[200002],w[200002],c1[200002],c2[200002];
map<edgex,ll>mp;
bool vis[200002];
inline void eat(int pos,bool lv,ll v){
	if(lv)a[pos]=min(a[pos],v);
	else tag[pos]=min(tag[pos],v);
}
inline void pd(int pos,int l,int r){
	ri mid=(l+r)>>1;
	eat(pos<<1,l==mid,tag[pos]);
	eat(pos<<1|1,r==mid+1,tag[pos]);
}
inline void add(int pos,int l,int r,int ql,int qr,ll v){
	if(l>=ql&&r<=qr){
		eat(pos,l==r,v);
		return;
	}if(ql>r||qr<l)return;
	ri mid=(l+r)>>1;
	pd(pos,l,r);
	add(pos<<1,l,mid,ql,qr,v);
	add(pos<<1|1,mid+1,r,ql,qr,v);
}
inline ll qr(int pos,int l,int r,int ql){
	if(l==r)return a[pos];
	ri mid=(l+r)>>1;
	pd(pos,l,r);
	if(ql<=mid)return qr(pos<<1,l,mid,ql);
	return qr(pos<<1|1,mid+1,r,ql);
}
inline void spfa(){
	memset(dis,0x3f,sizeof(dis));
	memset(a,0x3f,sizeof(a));
	memset(tag,0x3f,sizeof(tag));
	dis[1]=0;
	queue<int>q;
	q.push(1);
	vis[1]=1;
	ri pos;
	while(!q.empty()){
		pos=q.front();
		q.pop();
		F(i,0,g[pos].size()-1){
			if(dis[g[pos][i]]>dis[pos]+w[pos][i]){
				f1[g[pos][i]]=pos;
				dis[g[pos][i]]=dis[pos]+w[pos][i];
				if(!vis[g[pos][i]]){
					vis[g[pos][i]]=1;
					q.push(g[pos][i]);
				}
			}
		}
		vis[pos]=0;
	}
}
inline void spfa2(){
	memset(dis2,0x3f,sizeof(dis2));
	memset(vis,0,sizeof(vis));
	dis2[n]=0;
	queue<int>q;
	q.push(n);
	vis[n]=1;
	ri pos;
	while(!q.empty()){
		pos=q.front();
		q.pop();
		F(i,0,g[pos].size()-1){
			if(dis2[g[pos][i]]>dis2[pos]+w[pos][i]){
				f2[g[pos][i]]=pos;
				dis2[g[pos][i]]=dis2[pos]+w[pos][i];
				if(!vis[g[pos][i]]){
					vis[g[pos][i]]=1;
					q.push(g[pos][i]);
				}
			}
		}
		vis[pos]=0;
	}for(register int i=1;i;i=f2[i])o[++cnt]=i,num[i]=cnt;
}
inline void dfs(int pos){
	if(num[pos])x1[pos]=pos;
	else x1[pos]=x1[f1[pos]];
	F(i,0,c1[pos].size()-1)dfs(c1[pos][i]);
}
inline void dfs2(int pos){
	if(num[pos])x2[pos]=pos;
	else x2[pos]=x2[f2[pos]];
	F(i,0,c2[pos].size()-1)dfs2(c2[pos][i]);
}
inline bool ison(int pos){
	if(ed[pos].two)return 0;
	if(labs(num[ed[pos].u]-num[ed[pos].v])!=1)return 0;
	if(num[ed[pos].u]<num[ed[pos].v]){
		return (dis[ed[pos].v]-dis[ed[pos].u]==ed[pos].w);
	}else{
		return (-dis[ed[pos].v]+dis[ed[pos].u]==ed[pos].w);
	} 
}
int main(){
    cin>>n>>m>>q;
    F(i,1,m){
    	t1=read(),t2=read(),t3=read();
    	ed[i]=(edge){t1,t2,t3,0};
    	if(t4=mp[(edgex){t1,t2,t3}]){
    		ed[i].two=1;
    		ed[t4].two=1;
		}else{
			mp[(edgex){t1,t2,t3}]=i;
			mp[(edgex){t2,t1,t3}]=i;
		}
    	g[t1].push_back(t2);
    	g[t2].push_back(t1);
    	w[t1].push_back(t3);
    	w[t2].push_back(t3);
	}spfa(),spfa2();
	F(i,1,n){
		c1[f1[i]].push_back(i);
		c2[f2[i]].push_back(i);
	}dfs(1),dfs2(n);
	F(i,1,m){
		if(ison(i))continue;
		//cout<<i<<endl;
		if(num[x1[ed[i].u]]<num[x2[ed[i].v]])
			add(1,1,n+1,num[x1[ed[i].u]],num[x2[ed[i].v]]-1,dis2[ed[i].v]+dis[ed[i].u]+ed[i].w);
		//	cout<<ed[i].u<<' '<<ed[i].v<<' '<</*dis2[ed[i].v]+dis[ed[i].u]+*/ed[t1].w<<endl;
		if(num[x2[ed[i].u]]>num[x1[ed[i].v]])
			add(1,1,n+1,num[x1[ed[i].v]],num[x2[ed[i].u]]-1,dis[ed[i].v]+dis2[ed[i].u]+ed[i].w);
	}
	F(i,1,q){
		t1=read(),t2=read();
		if(t2>ed[t1].w){
			if(ison(t1)){
				ri pos=min(num[ed[t1].u],num[ed[t1].v]);
				cout<<min(dis[n]+t2-ed[t1].w,qr(1,1,n+1,pos))<<endl;
			}else{
				printf("%lld\n",dis[n]);
			}
		}else{
			if(ison(t1)){
				printf("%lld\n",dis[n]+t2-ed[t1].w);
			}else{
				cout<<min(dis[n],min(dis[ed[t1].u]+t2+dis2[ed[t1].v],dis2[ed[t1].u]+t2+dis[ed[t1].v]))<<endl;
			}
		}
	}
    return 0;
}