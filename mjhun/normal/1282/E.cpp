#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int n;
map<pair<int,int>,vector<int> > w;
int z[100005][3];
int d[100005];
vector<int> g[100005];
queue<int> q;
int r0[100005],r1[100005];

void dfs(int x, int p, int k){
	r0[k]=x;
	if(p<0)dfs(g[x][0],x,k+1);
	else if(!x)return;
	else dfs(g[x][0]^g[x][1]^p,x,k+1);
}

int main(){
	int tn;
	scanf("%d",&tn);
	while(tn--){
		scanf("%d",&n);
		w.clear();
		fore(i,0,n)g[i].clear();
		fore(i,0,n-2){
			d[i]=3;
			fore(j,0,3)scanf("%d",&z[i][j]),z[i][j]--;
			sort(z[i],z[i]+3);
			fore(j,0,3)fore(k,j+1,3)w[mp(z[i][j],z[i][k])].pb(i);
		}
		for(auto p:w)if(SZ(p.snd)==1){
			int x=p.fst.fst,y=p.fst.snd;
			g[x].pb(y),g[y].pb(x);
			d[p.snd[0]]--;
			if(d[p.snd[0]]==1)q.push(p.snd[0]);
		}
		fore(k,0,n-2){
			int t=q.front();q.pop();
			r1[k]=t;
			fore(i,0,3)fore(j,i+1,3){
				int x=z[t][i],y=z[t][j];
				auto&& v=w[mp(x,y)];
				v.erase(remove(v.begin(),v.end(),t),v.end());
				if(SZ(v)==1){
					d[v[0]]--;
					if(d[v[0]]==1)q.push(v[0]);
				}
			}
		}
		assert(q.empty());
		dfs(0,-1,0);
		fore(i,0,n)printf("%d%c",r0[i]+1," \n"[i==n-1]);
		fore(i,0,n-2)printf("%d%c",r1[i]+1," \n"[i==n-3]);
	}
	return 0;
}