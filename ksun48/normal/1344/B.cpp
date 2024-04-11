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

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for(int i = 0; i < n; i++) cin >> s[i];
	UF uf(n*m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(s[i][j] == '.') continue;
			if(i+1 < n && s[i+1][j] == '#') uf.join(i*m+j, (i+1)*m+j);
			if(j+1 < m && s[i][j+1] == '#') uf.join(i*m+j, i*m+(j+1));
		}
	}
	bool emptyrow = false, emptycol = false;
	for(int i = 0; i < n; i++){
		int cur = 0;
		if(s[i][0] == '#') cur++;
		for(int j = 1; j < m; j++){
			if(s[i][j] != s[i][j-1]) cur++;
		}
		if(s[i][m-1] == '#') cur++;
		if(cur > 2){
			cout << -1 << '\n';
			return 0;
		}
		if(cur == 0) emptyrow = true;
	}
	for(int j = 0; j < m; j++){
		int cur = 0;
		if(s[0][j] == '#') cur++;
		for(int i = 1; i < n; i++){
			if(s[i][j] != s[i-1][j]) cur++;
		}
		if(s[n-1][j] == '#') cur++;
		if(cur > 2){
			cout << -1 << '\n';
			return 0;
		}
		if(cur == 0) emptycol = true;
	}
	if(emptyrow != emptycol){
		cout << -1 << '\n';
		return 0;
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(s[i][j] == '.') continue;
			if(uf.find(i*m+j) == i*m+j) ans++;
		}
	}
	cout << ans << '\n';
}