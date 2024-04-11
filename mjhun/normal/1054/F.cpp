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

#define MAXN 2048

vector<int> g[MAXN];
int nn,mm;
int mt[MAXN],mt2[MAXN],ds[MAXN];
bool bfs(){
	queue<int> q;
	memset(ds,-1,sizeof(ds));
	fore(i,0,nn)if(mt2[i]<0)ds[i]=0,q.push(i);
	bool r=false;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int y:g[x]){
			if(mt[y]>=0&&ds[mt[y]]<0)ds[mt[y]]=ds[x]+1,q.push(mt[y]);
			else if(mt[y]<0)r=true;
		}
	}
	return r;
}
bool dfs(int x){
	for(int y:g[x])if(mt[y]<0||ds[mt[y]]==ds[x]+1&&dfs(mt[y])){
		mt[y]=x;mt2[x]=y;return true;
	}
	ds[x]=1<<30;
	return false;
}
int match(){
	int r=0;
	memset(mt,-1,sizeof(mt));memset(mt2,-1,sizeof(mt2));
	while(bfs())fore(i,0,nn)if(mt2[i]<0)r+=dfs(i);
	return r;
}


int n,nx,ny;
int x[1024],y[1024];
int xs[1024],ys[1024];

bool b[1024][1024]; // true->libre
int row[1024][1024];
int col[1024][1024];

int ri[2048],rs[2048],re[2048],nr;
int cj[2048],cs[2048],ce[2048],nc;

bool tr[2048],tc[2048];

vector<pair<int,pair<int,int> > > r0,r1;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d%d",x+i,y+i),xs[i]=x[i],ys[i]=y[i];
	sort(xs,xs+n);nx=unique(xs,xs+n)-xs;
	sort(ys,ys+n);ny=unique(ys,ys+n)-ys;
	fore(i,0,n){
		x[i]=lower_bound(xs,xs+nx,x[i])-xs;
		y[i]=lower_bound(ys,ys+ny,y[i])-ys;
	}
	mset(b,true);
	fore(i,0,n)b[x[i]][y[i]]=false;
	fore(i,0,nx){
		int j=0;
		while(j<ny){
			if(!b[i][j]){j++;continue;}
			ri[nr]=i;
			rs[nr]=j;
			while(j<ny&&b[i][j])row[i][j]=nr,j++;
			re[nr]=j;
			nr++;
		}
	}
	fore(j,0,ny){
		int i=0;
		while(i<nx){
			if(!b[i][j]){i++;continue;}
			cj[nc]=j;
			cs[nc]=i;
			while(i<nx&&b[i][j])col[i][j]=nc,i++;
			ce[nc]=i;
			nc++;
		}
	}
	fore(i,0,nr)tr[i]=rs[i]==0||re[i]==ny;
	fore(i,0,nc)tc[i]=cs[i]==0||ce[i]==nx;
	fore(i,0,nx)fore(j,0,ny)if(b[i][j]&&!tr[row[i][j]]&&!tc[col[i][j]]){
		//printf(" %d %d\n",row[i][j],col[i][j]);
		g[row[i][j]].pb(col[i][j]);
	}
	nn=nr;mm=nc;
	int asd=match();//printf(" mm %d\n",asd);
	fore(i,0,nr)if(!tr[i])tr[i]=ds[i]<0,asd-=tr[i];
	fore(i,0,nc)if(!tc[i])tc[i]=mt[i]>=0&&ds[mt[i]]>=0,asd-=tc[i];
	//printf(" pingo %d\n",asd);
	//assert(!asd);
	fore(i,0,nx){
		int j=0;
		while(j<ny){
			if(b[i][j]&&tr[row[i][j]]){j++;continue;}
			int t=j;
			while(j<ny&&(!b[i][j]||!tr[row[i][j]])){
				j++;
			}
			r0.pb(mp(i,mp(t,j)));
		}
	}
	fore(j,0,ny){
		int i=0;
		while(i<nx){
			if(b[i][j]&&tc[col[i][j]]){i++;continue;}
			int t=i;
			while(i<nx&&(!b[i][j]||!tc[col[i][j]])){
				i++;
			}
			r1.pb(mp(j,mp(t,i)));
		}
	}
	printf("%d\n",SZ(r1));
	for(auto p:r1)printf("%d %d %d %d\n",xs[p.snd.fst],ys[p.fst],xs[p.snd.snd-1],ys[p.fst]);
	printf("%d\n",SZ(r0));
	for(auto p:r0)printf("%d %d %d %d\n",xs[p.fst],ys[p.snd.fst],xs[p.fst],ys[p.snd.snd-1]);
	return 0;
}