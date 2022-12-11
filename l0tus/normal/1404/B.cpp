#include <bits/stdc++.h>
#define va first
#define vb second
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;

const int MN = 1e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

int par[MN],dep[MN];
vector<int> G[MN];

void dfs(int s)
{
	for(int e:G[s]){
		if(e==par[s]) continue;
		dep[e] = dep[s]+1;
		par[e] = s;
		dfs(e);
	}
}


int main()
{
	#ifdef L0TUS
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\input.txt", "r", stdin);
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\output.txt", "w", stdout);
	#endif
	
    ios_base::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
    	int N,A,B,DA,DB;
    	cin >> N >> A >> B >> DA >> DB;
    	for(int i=1; i<=N; i++){
    		G[i].clear();
    		par[i] = dep[i] = 0;
    	}
    	for(int i=1; i<N; i++){
    		int u,v;
    		cin >> u >> v;
    		G[u].push_back(v);
    		G[v].push_back(u);
    	}
    	dfs(B);
    	if(dep[A]<=DA||DB<=2*DA) cout << "Alice\n";
    	else{
	    	int x = 1;
	    	for(int i=1; i<=N; i++){
	    		if(dep[i]>dep[x]) x = i;
	    	}
	    	for(int i=1; i<=N; i++){
	    		par[i] = dep[i] = 0;
	    	}
	    	dfs(x);
	    	x = 0;
	    	for(int i=1; i<=N; i++){
	    		x = max(x,dep[i]);
	    	}
	    	if(x<=2*DA) cout << "Alice\n";
	    	else cout << "Bob\n"; 
    	}
    }
}