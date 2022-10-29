#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

#define S 105

vector<int> g[100005];
int n;
int r[100005];
int rr;

int dfs(int x, int p, int k){ // cuanto me sobra
	int a=-(1<<30),b=-(1<<30); // mayor, segundo mayor
	for(int y:g[x]){
		if(y==p)continue;
		int t=dfs(y,x,k);
		if(t>a)b=a,a=t;
		else if(t>b)b=t;
	}
	if(a<0)return 1;
	if(b<0){
		if(a+1==k){
			rr++;
			return 0;
		}
		return a+1;
	}
	if(a+b+1>=k){
		rr++;
		return 0;
	}
	return a+1;
}

int mem[100005];

int doit(int k){
	if(mem[k]>=0)return mem[k];
	rr=0;
	dfs(0,-1,k);
	return mem[k]=rr;
}


int main(){
	mset(mem,-1);
	scanf("%d",&n);
	fore(_,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	r[1]=n;
	fore(i,2,1005)r[i]=doit(i);
	int k=n;
	fore(i,1,S){
		int s=1,e=n+1;
		while(e-s>1){
			int m=(s+e)/2;
			if(doit(m)>=i)s=m;
			else e=m;
		}
		// s mayor que tiene cantidad i
		while(k>s)r[k]=i-1,k--;
	}
	fore(i,1,n+1)printf("%d\n",r[i]);
	return 0;
}