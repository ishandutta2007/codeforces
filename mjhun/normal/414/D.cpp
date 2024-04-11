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

int n,k;ll p;
vector<int> g[100005];
int d[100005];
ll s[100005];

void dfs(int x, int dd, int p){
	d[x]=dd;
	for(int y:g[x]){
		if(y==p)continue;
		dfs(y,dd+1,x);
	}
}

bool ok(int a, int b){
	return 1LL*(b-a)*d[b-1]-(s[b]-s[a])<=p;
}


int main(){
	scanf("%d%d%lld",&n,&k,&p);
	fore(_,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(0,0,-1);
	sort(d,d+n);
	fore(i,0,n)s[i+1]=s[i]+d[i];
	int r=1;
	fore(i,1,n){
		int a=1,b=i+1;
		while(b-a>1){
			int m=(a+b)/2;
			if(ok(m-1,i+1))b=m;
			else a=m;
		}
		r=max(r,i-a+1);
	}
	printf("%d\n",min(r,k));
	return 0;
}