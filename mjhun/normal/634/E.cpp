#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,qwe;
int a[200005];
vector<int> g[200005];
set<int> w[200005];
bool b[200005];
int v[200005];
bool vis[200005];
int d[200005];
stack<int> st;
vector<int> c;

void dfs(int x, int f){
	vis[x]=true;
	c.pb(x);
	for(set<int>::iterator it=w[x].begin();it!=w[x].end();++it){
		int y=*it;
		if(y==f)continue;
		d[y]=d[x]+v[y];
		dfs(y,x);
	}
}

int diam(int x){
	c.clear();
	d[x]=v[x];
	dfs(x,-1);
	int y=x;
	fore(i,1,c.size()){
		if(d[c[i]]>d[y])y=c[i];
	}
	d[y]=v[y];
	c.clear();
	dfs(y,-1);
	int r=0;
	fore(i,0,c.size())r=max(r,d[c[i]]);
	return r;
}

bool can(int m){
	fore(x,0,n)w[x].clear();
	memset(b,false,sizeof(b));
	memset(v,0,sizeof(v));
	fore(x,0,n){
		fore(i,0,g[x].size()){
			int y=g[x][i];
			if(a[x]<m||a[y]<m){
				b[x]=b[y]=true;
			}
			else {
				w[x].insert(y);
				w[y].insert(x);
			}
		}
		if(a[x]>=m)v[x]=1;
	}
	fore(x,0,n){
		if(!b[x]&&w[x].size()==1)st.push(x);
	}
	while(!st.empty()){
		int x=st.top();st.pop();
		int y=*w[x].begin();
		w[x].erase(y);
		w[y].erase(x);
		v[y]+=v[x];
		if(!b[y]&&w[y].size()==1)st.push(y);
	}
	memset(vis,false,sizeof(vis));
	int r=0;
	fore(x,0,n){
		if(!vis[x])r=max(r,diam(x));
	}
	return r>=qwe;
}

int main(){
	int k;
	scanf("%d%d",&n,&qwe);
	fore(i,0,n)scanf("%d",a+i);
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	int s=1,e=1000001;
	while(e-s>1){
		int m=(s+e)/2;
		if(can(m))s=m;
		else e=m;
	}
	printf("%d\n",s);
	return 0;
}