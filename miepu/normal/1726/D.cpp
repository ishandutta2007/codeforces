#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx,id;
}e[N];int hd[N],S;
void add(int fr,int to,int id){
    e[++S]=(edge){to,hd[fr],id},hd[fr]=S;
}

int n,m;
int fa[N];
int res[N];
int gf(int k){
	return k==fa[k]?k:fa[k]=gf(fa[k]);
}

vector<edge> dl;

int dep[N],idk[N];
void dfs(int k,int fa){
	dep[k]=dep[fa]+1;
	fore(k)if(_to!=fa)
		idk[_to]=e[i].id,dfs(_to,k);
}

int cut(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	return idk[u];
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)fa[i]=i,hd[i]=0;
	S=0;
	dl.clear();
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		int X=gf(x),Y=gf(y);
		if(X==Y){
			res[i]=0;
			dl.push_back({x,y,i});
		}
		else {
			fa[X]=Y;
			res[i]=1;
			add(x,y,i);
			add(y,x,i);
		}
	}
	if(m==n+2){
		map<int,int> A;
		for(auto x:dl){
			A[x.to]++;
			A[x.nx]++;
		}
		dfs(1,0);
		if(A.size()==3){
			res[cut(dl[0].to,dl[0].nx)]=0;
			res[dl[0].id]=1;
		}
	}
	for(int i=1;i<=m;i++)cout<<res[i];
	cout<<'\n';
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}