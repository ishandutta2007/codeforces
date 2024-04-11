/*long long or int&the MAX_INT or MIN_INT*/
/*the size of a[]&inline*/
/*xx 396*/
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ldb;
template<class T>inline void checkmin(T &a,const T &b){if(b<a)a=b;}
template<class T>inline void checkmax(T &a,const T &b){if(b>a)a=b;}
const int maxn=2e5+10;
bool del[maxn],f[maxn],vis[maxn];
int n,sz[maxn],lst[maxn],fa[maxn];
vector<pair<int,int> >g[maxn];
vector<int>v;
void dfs(int x,int f){
	sz[x]=1;vis[x]=true;fa[x]=f;v.pb(x);
	for(int i=0;i<(int)g[x].size();i++){
		int to=g[x][i].fst,id=g[x][i].snd;
		if(to==f||del[id])continue;
		dfs(to,x);
		sz[x]+=sz[to];
	}
}
int main(){
	int a=1,b=1;f[a]=f[b]=true;
	while(a+b<maxn){
		int t=a;a=b;b=t+b;
		f[a]=f[b]=true;lst[b]=a;
	}
	cin>>n;
	for(int i=0;i<n-1;i++){
		int u,v;cin>>u>>v;u--;v--;
		g[u].pb(mp(v,i));g[v].pb(mp(u,i));
	}
	for(int dep=0;dep<20;dep++){
		for(int i=0;i<n;i++){
			if(!vis[i]){
				v.clear();dfs(i,-1);
				if(f[sz[i]]==false){
					cout<<"NO\n";
					return 0;
				}
				if(sz[i]==2||sz[i]==1)continue;
				bool ok=false;
				for(int j=0;j<(int)v.size();j++){
					int x=v[j];
					if(ok)break;
					for(int k=0;k<(int)g[x].size();k++){
						int to=g[x][k].fst,id=g[x][k].snd;
						if(ok)break;
						if(del[id])continue;
						if(to==fa[x]&&sz[i]-sz[x]==lst[lst[sz[i]]])del[id]=ok=true;
						if(to!=fa[x]&&sz[to]==lst[lst[sz[i]]])del[id]=ok=true;
					}
				}
				if(!ok){
					cout<<"NO\n";
					return 0;
				}
			}
		}
		for(int i=0;i<n;i++)vis[i]=false;
	}
	cout<<"YES\n";
	return 0;
}