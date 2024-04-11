#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	string s, t;
	cin >> s >> t;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	string z;
	int i = 0;
	int j = 0;
	int ri = 0;
	int rj = 0;
	while(i < s.size() && j < t.size()){
		if((rj == k || (ri != k && s[i] < t[j]))){
			z += s[i];
			i++;
			ri++;
			rj = 0;
		} else {
			z += t[j];
			j++;
			rj++;
			ri = 0;
		}
	}
	cout << z << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}