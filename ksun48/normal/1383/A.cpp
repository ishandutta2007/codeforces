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
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	UF uf(26);
	for(int i = 0; i < n; i++){
		if(s[i] > t[i]){
			cout << -1 << '\n';
			return;
		}
		uf.join(s[i] - 'a', t[i] - 'a');
	}
	int ans = 0;
	for(int i = 0; i < 26; i++){
		if(uf.find(i) != i) ans++;
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}