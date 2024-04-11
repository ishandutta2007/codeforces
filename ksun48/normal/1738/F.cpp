#include <bits/stdc++.h>
using namespace std;

struct UF {
    int n;
    vector<int> par;
    UF(int _n) : n(_n) {
        for(int i = 0; i < n; i++) par.push_back(i);
    }
    int find(int a){
        if(a != par[a]) par[a] = find(par[a]);
        return par[a];
    }
    bool join(int a, int b){
        a = find(a);
        b = find(b);
        par[a] = b;
        return (a != b);
    }
};

void solve(){
	int N;
	cin >> N;
	vector<int> deg(N);
	for(int& x : deg) cin >> x;
	vector<int> ord(N);
	for(int i = 0; i < N; i++) ord[i] = i;
	sort(ord.begin(), ord.end(), [&](int x, int y) { return deg[x] > deg[y]; });
	vector<int> seen(N, 0);
	UF uf(N);
	for(int v : ord){
		if(seen[v]) continue;
		int d = deg[v];
		while(d){
			cout << "? " << (v+1) << '\n';
			cout << flush;
			int w;
			cin >> w;
			w--;
			seen[v] = true;
			if(seen[w]){
				uf.join(v, w);
				break;
			} else {
				seen[w] = true;
				uf.join(v, w);
				d--;
			}
		}
	}
	cout << "!";
	for(int i = 0; i < N; i++){
		cout << ' ' << (uf.find(i) + 1);
	}
	cout << '\n';
	cout << flush;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}