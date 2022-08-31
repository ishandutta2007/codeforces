#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int fl = 0;
	int ci = 0;
	int cj = n-1;
	vector<int> w;
	for(int i = n-1; i >= 0; i--){
		if(fl == 0){
			if(b[i] == a[ci]){
				w.push_back(1);
			}
			w.push_back(cj - ci + 1);
			ci++;
			fl = 1;
		} else {
			if(b[i] != a[cj]){
				w.push_back(1);
			}
			w.push_back(cj - ci + 1);
			cj--;
			fl = 0;
		}
	}
	cout << w.size();
	for(int r : w) cout << ' ' << r;
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}