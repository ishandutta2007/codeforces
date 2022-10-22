#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define endout fflush(stdout)
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=4e5+10;
int a[N],val[N],c[N],v[N];
set<int> s[N];
int n,m;
int head[N],to[N*10],nxt[N*10],cnt;
void add(int u,int v){
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}
inline int id(int i,int j){
	return (i-1)*m+j;
}
int ok[N],d[N],mn[N];
char ch[N];
int dfn[N],low[N],idx,in[N],stk[N],tp,hv[N];
int scnt,num[N];vector<int> g[N];int deg[N];
int bk[N];
void tarjan(int u){
	dfn[u]=low[u]=++idx;
	in[u]=1,stk[++tp]=u;
	go(u){
		int v=to[i];
		if(!dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
		else if(in[v])low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		scnt++;int x;
		do x=stk[tp--],in[x]=0,num[x]=scnt,hv[scnt]|=v[x],mn[scnt]=min(mn[scnt],bk[u]);
		while(x!=u);
	}
}
map<int,int> mp[N];
#define pi pair<int,int>
#define fi first
#define se second
queue<int> q;
vector<int> h;// 
void topo1(){
	For(i,1,n*m)if(!(d[i]=deg[i]))q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		if(hv[u]&&!ok[u])h.push_back(u);
		ok[u]|=hv[u];
		for(int v:g[u]){
			ok[v]|=ok[u];
			if(!--d[v])q.push(v);
		}
	}
}
int tmp[N],L[N],R[N],nu[N],deg2[N];
vector<int> g2[N];
void topo2(int op){
	For(i,1,scnt)if(!(d[i]=deg2[i]))q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		if(nu[u]){
			if(op==1)tmp[u]=min(tmp[u],nu[u]);
			else tmp[u]=max(tmp[u],nu[u]);
		}for(int v:g2[u]){
			if(op==1)tmp[v]=min(tmp[v],tmp[u]);
			else tmp[v]=max(tmp[v],tmp[u]);
			if(!--d[v])q.push(v);
		}
	}
}
bool cmp(int a,int b){return mn[a]<mn[b];} 
vector<pi> b;
signed main(){
	memset(mn,0x3f,sizeof mn);
	n=read(),m=read();For(i,1,n){
		scanf("%s",ch+1);For(j,1,m)if(ch[j]=='#')
			a[id(i,j)]=1,bk[id(i,j)]=j,s[j].insert(i);
	}For(j,1,m)s[j].insert(n+1);
	For(i,1,m)val[i]=read();
	For(j,1,m)Rof(i,n,1)if(a[id(i,j)]==1){
		if(++c[j]<=val[j])v[id(i,j)]=1;
		if(i>1){
			if(a[id(i-1,j)])add(id(i,j),id(i-1,j));
		}auto it=s[j].upper_bound(i);
		int k=*it;
		if(k<=n)add(id(i,j),id(k,j));
		if(j>1){ 
			it=s[j-1].lower_bound(i);
			if(*it<=k&&*it<=n)add(id(i,j),id(*it,j-1));
		}if(j<m){
			it=s[j+1].lower_bound(i);
			if(*it<=k&&*it<=n)add(id(i,j),id(*it,j+1));
		}
	}
	For(i,1,n*m)if(!dfn[i]&&a[i])tarjan(i);
//	cout<<scnt<<endl;For(i,1,scnt)printf("[%d] {%d}\n",mn[i],hv[i]);
	For(u,1,n*m)go(u)if(num[u]!=num[to[i]]&&!mp[num[u]][num[to[i]]]){
		int x=num[u],y=num[to[i]];
		g[x].push_back(y);
		g2[y].push_back(x);
//		printf("edge %d->%d\n",x,y);
		mp[x][y]=1,deg[y]++,deg2[x]++; 
	}
	topo1(),sort(h.begin(),h.end(),cmp);int idx=0;for(auto v:h)nu[v]=++idx;//,cout<<v<<endl;
	// 
	For(i,1,scnt)tmp[i]=1e9;topo2(1);For(i,1,scnt)L[i]=tmp[i];
	For(i,1,scnt)tmp[i]=-99;topo2(2);For(i,1,scnt)R[i]=tmp[i];
//	cout<<"all = "<<idx<<endl;
	For(i,1,scnt){
		int l=L[i],r=R[i];
		if(l<=r)b.push_back(pi(l,-r));//,printf("(%d): [%d,%d]\n",i,l,r);
	}sort(b.begin(),b.end());int now=0,mx=0,ans=0;
	for(auto v:b){
		int l=v.fi,r=-v.se;
		mx=max(mx,r); 
		if(l>now)now=mx,ans++;
		else mx=max(mx,r); 
	}cout<<ans<<endl;
	return 0;
}//dsad