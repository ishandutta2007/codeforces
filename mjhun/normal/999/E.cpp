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

vector<int> g[1<<19];
bool vis0[1<<19],vis1[1<<19];

void dfs0(int x){
	if(vis0[x])return;
	vis0[x]=true;
	for(int y:g[x])dfs0(y);
}

stack<int> st;

void dfs1(int x){
	if(vis0[x]||vis1[x])return;
	vis1[x]=true;
	for(int y:g[x])dfs1(y);
	st.push(x);
}

int n,m,s;

int main(){
	scanf("%d%d%d",&n,&m,&s);s--;
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);
	}
	dfs0(s);
	fore(i,0,n)dfs1(i);
	int r=0;
	while(!st.empty()){
		int x=st.top();st.pop();
		if(vis0[x])continue;
		r++;
		dfs0(x);
	}
	printf("%d\n",r);
	return 0;
}