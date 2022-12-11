#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
const int MN = 2e5+5;
int d[MN],dep[MN];
vector<int> G[MN];
int L=1,R;
bool odd,even;
void dfs(int s, int r)
{
	int cnt = 0;
	if(d[s]==1){
		if(dep[s]%2){
			if(even) L = 3;
			odd = 1;
		}
		else{
			if(odd) L = 3; 
			even = 1;
		}
	}
	for(int e:G[s]){
		if(e==r) continue;
		dep[e] = dep[s]+1;
		if(d[e]==1){
			cnt++;
		}
		dfs(e,s);
	}
	if(cnt) R -= cnt-1;
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int N;
    cin >> N;
    int k=0,u,v;
    R = N-1;
    for(int i=1; i<N; i++){
    	cin >> u >> v;
    	G[u].push_back(v);
    	G[v].push_back(u);
    	d[u]++;
    	d[v]++;
    	if(d[k]<d[u]) k = u;
    	if(d[k]<d[v]) k = v;
    }
    dfs(k,k);
    cout << L << ' ' << R;
}