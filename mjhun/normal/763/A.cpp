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

vector<int> g[100005];
int n,x=-1,y=-1;
int c[100005];

bool dfs(int x, int f){
	for(int y:g[x]){
		if(y==f)continue;
		if(f>=0&&c[y]!=c[x])return false;
		if(!dfs(y,x))return false;
	}
	return true;
}

int main(){
	scanf("%d",&n);
	fore(_,1,n){
		int a,b;
		scanf("%d%d",&a,&b);a--;b--;
		g[a].pb(b);g[b].pb(a);
	}
	fore(i,0,n)scanf("%d",c+i);
	fore(i,0,n)for(int j:g[i])if(c[i]!=c[j])x=i,y=j;
	if(x<0)puts("YES\n1");
	else if(dfs(x,-1))printf("YES\n%d\n",x+1);
	else if(dfs(y,-1))printf("YES\n%d\n",y+1);
	else puts("NO");
	return 0;
}