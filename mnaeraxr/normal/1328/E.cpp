#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
const int oo = 0x3f3f3f3f;
const double pi = acos(-1);
const double eps = 1e-9;
 
#define endl '\n'
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int n, m;
	cin >> n >> m;
 
	vi P(n);
	vi L(n);
 
	vector<vi> T(n, vi());
	for (int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		T[u].push_back(v);
		T[v].push_back(u);
	}
 
	vi B(n);
	vi E(n);
	int id = 0;

    function<void(int,int)> dfs = [&](int a, int p) {
        L[a] = id;
        P[a] = p;
        B[a] = id++;
    
        for (int b : T[a]){
            if (b == p) continue;
            dfs(b, a);
        }
        E[a] = id++;
    };
    
    dfs(0, 0);

	while (m--){
		int mx = 0;
		int longest = 0;
 
		int q;
		cin >> q;
		vi V(q);
		for (int i = 0; i < q; ++i){
			cin >> V[i];
			V[i] = P[V[i] - 1];
			if (L[V[i]] > mx){
				mx = L[V[i]];
				longest = V[i];
			}
		}
 
		bool ok = true;
		for (int i = 0; i < q; ++i){
			if (L[longest] < L[V[i]] || L[longest] > E[V[i]]){
				ok = false;
				break;
			}
		}
 
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
 
	return 0;
}