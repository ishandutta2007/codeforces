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

int n,m,d,r=100;
int w[100005];
bool vis[1<<20];

void dfs(int w){
	if(vis[w])return;
	vis[w]=true;
	fore(i,0,m)dfs(w&(~(1<<i)));
}

int main(){
	scanf("%d%d%d",&n,&m,&d);
	fore(i,0,m){
		int q;vector<int> v;
		scanf("%d",&q);
		while(q--){
			int t;
			scanf("%d",&t);t--;
			v.pb(t);
		}
		sort(v.begin(),v.end());
		int k=0;
		fore(j,0,n-d+1){
			while(k<SZ(v)&&v[k]<j)k++;
			if(k<SZ(v)&&v[k]<j+d)w[j]|=1<<i;
		}
	}
	fore(i,0,n-d+1)dfs(w[i]^((1<<m)-1));
	fore(i,0,1<<m)if(!vis[i])r=min(r,__builtin_popcount(i));
	printf("%d\n",r);
	return 0;
}