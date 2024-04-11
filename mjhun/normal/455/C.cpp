#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

vector<int> g[300005];
vector<int> comp;
int d[300005];
bool vis[300005];
int di[300005];
int ce[300005];
int n,m,q;
int uf[300005];

int find(int x){
	if(uf[x]<0)return x;
	return uf[x]=find(uf[x]);
}

void join(int x, int y){
	if(x==y)return;
	if(uf[x]<uf[y])swap(x,y);
	uf[y]+=uf[x];
	uf[x]=y;
}

void dfs(int x){
	comp.pb(x);
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(vis[y])continue;
		vis[y]=true;
		d[y]=d[x]+1;
		dfs(y);
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	memset(uf,-1,sizeof(uf));
	fore(x,0,n){
		if(!vis[x]){
			comp.clear();
			vis[x]=true;d[x]=0;
			dfs(x);
			int k,dk=-1;
			fore(i,0,comp.size()){
				join(find(x),find(comp[i]));
				vis[comp[i]]=false;
				if(d[comp[i]]>dk){
					dk=d[comp[i]];
					k=comp[i];
				}
			}
			comp.clear();
			vis[k]=true;d[k]=0;
			dfs(k);
			dk=-1;
			fore(i,0,comp.size())dk=max(dk,d[comp[i]]);
			di[find(x)]=dk;
			fore(i,0,comp.size())if(d[comp[i]]==dk/2)ce[find(x)]=comp[i];
		}
	}
	while(q--){
		int t,a,b;
		scanf("%d%d",&t,&a);a--;
		if(t==1){
			printf("%d\n",di[find(a)]);
		}
		else {
			scanf("%d",&b);b--;
			a=find(a);b=find(b);
			if(a!=b){
				//printf("%d %d %d  %d %d %d\n",a,ce[a],di[a],b,ce[b],di[b]);
				join(a,b);
				int ab=find(a),dd=(di[a]+1)/2+(di[b]+1)/2+1;
				if((di[a]+1)/2>(di[b]+1)/2)ce[ab]=ce[a],di[ab]=max(di[a],dd);
				else if((di[a]+1)/2<(di[b]+1)/2)ce[ab]=ce[b],di[ab]=max(di[b],dd);
				else ce[ab]=ce[a],di[ab]=dd;
				//printf("%d %d %d\n",ab,ce[ab],di[ab]);
			}
		}
	}
	return 0;
}