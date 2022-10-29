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
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

vector<int> g[100005];
int n,m,s;int r=-1;
int f[100005][2];
int v[100005];

void dfs0(int x, int k){
	if(!SZ(g[x])&&k==1)r=x;
	for(int y:g[x]){
		if(f[y][k^1]>=0)continue;
		f[y][k^1]=x;
		dfs0(y,k^1);
	}
}

bool dfs1(int x){
	v[x]=-1;
	for(int y:g[x]){
		if(!v[y]){
			if(dfs1(y))return true;
		}
		else if(v[y]<0)return true;
	}
	v[x]=1;
	return false;
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n){
		int k;
		scanf("%d",&k);
		while(k--){
			int x;
			scanf("%d",&x);x--;
			g[i].pb(x);
		}
	}
	scanf("%d",&s);s--;
	memset(f,-1,sizeof(f));
	dfs0(s,0);
	if(r>=0){
		puts("Win");
		vector<int> z;
		int x=r,k=1;
		while(x!=s||k){
			z.pb(x);
			x=f[x][k];k^=1;
		}
		z.pb(s);
		reverse(z.begin(),z.end());
		fore(i,0,SZ(z))printf("%d%c",z[i]+1," \n"[i==SZ(z)-1]);
	}
	else if(dfs1(s))puts("Draw");
	else puts("Lose");
	return 0;
}