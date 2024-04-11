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
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

vector<pair<int,int> > rb;

int uf[1<<19];
int find(int x){
	if(uf[x]<0)return x;
	return find(uf[x]);
}
void join(int x, int y){
	assert(max(uf[x],uf[y])<0&&x!=y);
	if(uf[x]>uf[y])swap(x,y);
	rb.pb(mp(x,uf[x]));rb.pb(mp(y,uf[y]));
	uf[x]+=uf[y];
	uf[y]=x;
}
void asd(){
	reverse(rb.begin(),rb.end());
	for(auto p:rb)uf[p.fst]=p.snd;
	rb.clear();
}

int n,m,q;
int ex[1<<19],ey[1<<19],ec[1<<19];
map<int,vector<pair<int,int> > > w0;
map<int,vector<pair<int,vector<pair<int,int> > > > > w1;
bool r[1<<19];


int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,m)scanf("%d%d%d",ex+i,ey+i,ec+i),w0[ec[i]].pb(mp(ex[i],ey[i]));
	scanf("%d",&q);
	memset(uf,-1,sizeof(uf));
	memset(r,true,sizeof(r));
	fore(_,0,q){
		int k;
		map<int,vector<pair<int,int> > > w;
		scanf("%d",&k);
		bool can=true;
		rb.clear();
		fore(_,0,k){
			int i;
			scanf("%d",&i);i--;
			w[ec[i]].pb(mp(ex[i],ey[i]));
			int fx=find(ex[i]),fy=find(ey[i]);
			if(fx==fy){can=false;}
			else join(fx,fy);
		}
		asd();
		if(can){
			for(auto p:w)w1[p.fst].pb(mp(_,p.snd));
		}
		else r[_]=false;
	}
	auto it=w0.begin();
	for(auto p:w1){
		while(it->fst<p.fst){
			for(auto z:it->snd){
				int fx=find(z.fst),fy=find(z.snd);
				if(fx!=fy)join(fx,fy);
			}
			++it;
		}
		for(auto q:p.snd){
			rb.clear();
			for(auto z:q.snd){
				int fx=find(z.fst),fy=find(z.snd);
				if(fx!=fy)join(fx,fy);
				else r[q.fst]=false;
			}
			asd();
		}
	}
	fore(i,0,q)puts(r[i]?"YES":"NO");
	return 0;
}