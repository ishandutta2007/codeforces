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

int n;
pair<int,int> a[100005];
vector<vector<int> > r;
bool vis[100005];

int main(){
	while(scanf("%d",&n)!=EOF){
		fore(i,0,n){
			int x;
			scanf("%d",&x);
			a[i]=mp(x,i);
		}
		sort(a,a+n);
		memset(vis,false,sizeof(vis));r.clear();
		fore(i,0,n)if(!vis[i]){
			vector<int> v;
			int k=i;
			while(!vis[k])vis[k]=true,v.pb(k),k=a[k].snd;
			r.pb(v);
		}
		printf("%d\n",SZ(r));
		for(auto v:r){
			printf("%d",SZ(v));
			for(int k:v)printf(" %d",k+1);
			puts("");
		}
		puts("");
	}
	return 0;
}