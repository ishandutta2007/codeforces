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
int nq;
bool adj[1024][1024];

void init(){
#ifdef DEMETRIO
	int m;
	scanf("%d",&m);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		adj[x][y]=adj[y][x]=true;
	}
	//fore(i,0,n)adj[i][(i+1)%n]=adj[(i+1)%n][i]=true;
#endif
}

int ask(vector<int>& v){
	if(SZ(v)<=1)return 0;
	nq++;
	assert(nq<=20000);
#ifdef DEMETRIO
	int rr=0;
	fore(i,0,SZ(v))fore(j,i+1,SZ(v))rr+=adj[v[i]][v[j]];
	return rr;
	/*int q0=0,q1=0;
	bool a=false,b=false;
	for(int i:v){
		if(i%2)q0++;
		else q1++;
		if(i==0)a=true;
		if(i==2)b=true;
	}
	return q0*q1+(a&&b);*/
#endif
	printf("? %d\n",SZ(v));
	fore(i,0,SZ(v))printf("%d%c",v[i]+1," \n"[i==SZ(v)-1]);
	fflush(stdout);
	int r;
	scanf("%d",&r);assert(r>=0);
	return r;
}

int ask2(int x, vector<int>& v){
	v.pb(x);
	int r=ask(v);
	v.pop_back();
	r-=ask(v);
	return r;
}

int c[1024],f[1024],d[1024];
bool vis[1024];
vector<int> z;
//vector<int> g;
vector<int> asd;

void go(int x, int s, int e, int a, vector<int>& g){
	if(!a)return;
	if(a==e-s){
		fore(i,s,e)g.pb(z[i]);
		return;
	}
	int m=(s+e)/2;
	asd.clear();
	fore(i,s,m)asd.pb(z[i]);
	int t=ask2(x,asd);
	go(x,s,m,t,g);go(x,m,e,a-t,g);
}

void dfs(int x){
	vis[x]=true;
	z.clear();//g.clear();
	fore(i,0,n)if(!vis[i])z.pb(i);
	vector<int> g;
	go(x,0,SZ(z),ask2(x,z),g);
	for(int y:g)vis[y]=true;
	for(int y:g){
		c[y]=c[x]^1;
		f[y]=x;d[y]=d[x]+1;
		dfs(y);
	}
}

vector<int> w[2];

void pingo(vector<int> w){
	assert(SZ(w)>=2);
	//fore(i,0,SZ(w))printf("  %d",w[i]+1);puts("");
	//assert(ask(w));
	vector<int> v;
	v.pb(w[0]);
	v.pb(w[1]);
	int k=2;
	while(!ask(v))v.pb(w[k++]);
	int x=v.back(),y;
	for(int z:v){
		vector<int> qwe={x,z};
		if(ask(qwe)){y=z;break;}
	}
	//printf(" %d %d\n",x,y);
	vector<int> c0,c1;
	while(x!=y){
		if(d[x]>d[y]){
			c0.pb(x);
			x=f[x];
		}
		else {
			c1.pb(y);
			y=f[y];
		}
	}
	vector<int> r;
	for(int t:c0)r.pb(t);
	r.pb(x);
	reverse(c1.begin(),c1.end());
	for(int t:c1)r.pb(t);
	printf("N %d\n",SZ(r));
	fore(i,0,SZ(r))printf("%d%c",r[i]+1," \n"[i==SZ(r)-1]);
}

int main(){
	scanf("%d",&n);
	init();
	f[0]=-1;dfs(0);
	fore(i,0,n){
		assert(vis[i]);
		w[c[i]].pb(i);
	}
	if(ask(w[0])){
		pingo(w[0]);
	}
	else if(ask(w[1])){
		pingo(w[1]);
	}
	else {
		printf("Y %d\n",SZ(w[0]));
		fore(i,0,SZ(w[0]))printf("%d%c",w[0][i]+1," \n"[i==SZ(w[0])-1]);
	}
	//printf(" %d\n",nq);
	fflush(stdout);
	return 0;
}