#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

vector<int> g[100005];
vector<int> g2[100005];
vector<int> c[100005];
map<pair<int,int>,int> w;
pair<vector<int>,int> t[100005];
int n,m,nr;

void doit(int x, int y){
	int xx=x;
	c[nr].pb(x);
	w[mp(x,y)]=nr;
	while(y!=xx){
		c[nr].pb(y);
		int k=lower_bound(g[y].begin(),g[y].end(),x)-g[y].begin();
		x=y;y=g[y][(k+1)%g[y].size()];
		w[mp(x,y)]=nr;
	}
	if(c[nr].size()==n){
		fore(i,0,c[nr].size())w[mp(c[nr][i],c[nr][(i+1)%n])]=-1;
		c[nr].clear();
	}
	else nr++;
}
#define MAXN 100005
int r[MAXN];
bool tk[MAXN];
int fat[MAXN]; // father in centroid decomposition
int szt[MAXN]; // size of subtree
int calcsz(int x, int f){
	szt[x]=1;
	for(auto y:g2[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x);
	return szt[x];
}
void cdfs(int x=0, int f=-1, int sz=-1, int k=1){ // O(nlogn)
	if(sz<0)sz=calcsz(x,-1);
	for(auto y:g2[x])if(!tk[y]&&szt[y]*2>=sz){
		szt[x]=0;cdfs(y,f,sz,k);return;
	}
	tk[x]=true;fat[x]=f;
	r[x]=k;
	for(auto y:g2[x])if(!tk[y])cdfs(y,x,-1,k+1);
}
void centroid(){memset(tk,false,sizeof(tk));cdfs();}

int main(){
	scanf("%d%d",&n,&m);
	if(m==0){puts("1");return 0;}
	fore(i,0,m){
		int a,b;
		scanf("%d%d",&a,&b);a--;b--;
		g[a].pb(b);g[b].pb(a);
	}
	fore(i,0,n)g[i].pb((i+1)%n),g[(i+1)%n].pb(i);
	fore(i,0,n)sort(g[i].begin(),g[i].end());
	fore(x,0,n)for(int y:g[x])if(!w.count(mp(x,y)))doit(x,y);
	assert(nr==m+1);
	fore(i,0,nr){
//		for(int x:c[i])printf(" %d",x+1);puts("");
	}
	fore(x,0,nr){
		fore(j,0,c[x].size()){
			int y=w[mp(c[x][(j+1)%c[x].size()],c[x][j])];
			if(y>=0)g2[x].pb(y);
		}
		vector<int> q=c[x];
		sort(q.begin(),q.end());
		reverse(q.begin(),q.end());
		fore(i,0,q.size())q[i]=-q[i];
		t[x]=mp(q,x);
	}
	sort(t,t+nr);reverse(t,t+nr);
	centroid();
	fore(i,0,nr){
		if(i)putchar(' ');
		printf("%d",r[t[i].snd]);
	}
	puts("");
	return 0;
}