#include <bits/stdc++.h>
#define N 18
#define mp make_pair
#define fst first
#define snd second
using namespace std;
typedef long long ll;

int uf[1<<N];

int fnd(int k){
	if(uf[k]==k)return k;
	uf[k]=fnd(uf[k]);
	return uf[k];
}

int n,m;
int d[1<<N];
int f[N][1<<N];
int q[N][1<<N];
vector<pair<int,int> > t[1<<N];
vector<pair<int,pair<int,int> > > e;
vector<pair<int,pair<int,int> > > e2;

void dfs(int x){
	for(int i=0;i<t[x].size();++i){
		int y=t[x][i].fst;
		if(d[y]<0){
			d[y]=d[x]+1;
			f[0][y]=x;
			q[0][y]=t[x][i].snd;
			dfs(y);
		}
	}
}

void build(){
	memset(d,-1,sizeof(d));
	memset(f,-1,sizeof(f));
	memset(q,-1,sizeof(q));
	d[0]=0;
	dfs(0);
	for(int k=1;(1<<k)<n;++k){
		for(int i=0;i<n;++i){
			if(f[k-1][i]>=0){
				f[k][i]=f[k-1][f[k-1][i]];
				q[k][i]=max(q[k-1][i],q[k-1][f[k-1][i]]);
			}
		}
	}
}

int query(int x, int y){
	int r=-1;
	if(d[x]<d[y])swap(x,y);
	for(int k=N-1;k>=0;--k){
		if(d[x]-(1<<k)>=d[y]){
			r=max(r,q[k][x]);
			x=f[k][x];
		}
	}
	assert(d[x]==d[y]);
	if(x==y)return r;
	for(int k=N-1;k>=0;--k){
		if(f[k][x]>=0&&f[k][x]!=f[k][y]){
			r=max(r,max(q[k][x],q[k][y]));
			x=f[k][x];y=f[k][y];
		}
	}
	assert(f[0][x]==f[0][y]);
	return max(r,max(q[0][x],q[0][y]));
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e.push_back(mp(w,mp(u-1,v-1)));
		e2.push_back(mp(w,mp(u-1,v-1)));
	}
	sort(e.begin(),e.end());
	for(int i=0;i<n;++i)uf[i]=i;
	ll r=0;
	for(int i=0;i<m;++i){
		int f0=fnd(e[i].snd.fst),f1=fnd(e[i].snd.snd);
		if(f0!=f1){
			uf[f0]=f1;
			r+=e[i].fst;
			t[e[i].snd.fst].push_back(mp(e[i].snd.snd,e[i].fst));
			t[e[i].snd.snd].push_back(mp(e[i].snd.fst,e[i].fst));
		}
	}
	build();
	for(int i=0;i<m;++i){
		cout<<(r-query(e2[i].snd.fst,e2[i].snd.snd)+e2[i].fst)<<endl;
	}
	return 0;
}