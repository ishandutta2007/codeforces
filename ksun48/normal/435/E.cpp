#include <bits/stdc++.h>
using namespace std;

vector<string> flip(vector<string> a){
	vector<string> b(a[0].size(), string(a.size(), ' '));
	for(int i = 0; i < (int)a.size(); i++){
		for(int j = 0; j < (int)a[0].size(); j++){
			b[j][i] = a[i][j];
		}
	}
	return b;
}

bool ok(string s1, string s2){
	for(int i = 0; i < (int)s1.size(); i++){
		if(s1[i] != '0' && s2[i] != '0' && s1[i] != s2[i]) return false;
	}
	return true;
}

vector<string> solve(vector<string> a){
	int n = (int)a.size();
	int m = (int)a[0].size();
	for(int z = 0; z < 16; z++){
		if(__builtin_popcount(z) != 2) continue;
		vector<int> f, g;
		for(int j = 0; j < 4; j++){
			if((z >> j) & 1){
				f.push_back(j + 1);
			} else {
				g.push_back(j + 1);
			}
		}
		string s1, s2;
		string t1, t2;
		for(int v = 0; v < m; v++){
			s1 += ('0' + f[v & 1]);
			t1 += ('0' + g[v & 1]);
			s2 += ('0' + f[1 ^ (v & 1)]);
			t2 += ('0' + g[1 ^ (v & 1)]);
		}
		vector<string> newa = a;
		for(int i = 0; i < n; i++){
			if(i % 2 == 0){
				if(ok(a[i], s1)){
					newa[i] = s1;
				} else if(ok(a[i], s2)){
					newa[i] = s2;
				} else {
					goto failed;
				}
			} else {
				if(ok(a[i], t1)){
					newa[i] = t1;
				} else if(ok(a[i], t2)){
					newa[i] = t2;
				} else {
					goto failed;
				}
			}
		}
		return newa;
		failed:;
	}
	return {};
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<string> ares = solve(a);
	if(!ares.empty()){
		for(string x : ares){
			cout << x << '\n';
		}
		return 0;
	}
	vector<string> afres = solve(flip(a));
	if(!afres.empty()){
		afres = flip(afres);
		for(string x : afres){
			cout << x << '\n';
		}
		return 0;
	}
	cout << 0 << '\n';
}