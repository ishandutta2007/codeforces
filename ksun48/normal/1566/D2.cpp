#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	int N = n*m;
	vector<int> a(N);
	for(int& x : a){
		cin >> x;
	}
	vector<int> ord(N);
	for(int i = 0; i < N; i++){
		ord[i] = i;
	}
	sort(ord.begin(), ord.end(), [&](int x, int y){
		return tie(a[x], x) > tie(a[y], y);
	});
	for(int& x : a) x = -x;
	int inv = 0;
	for(int f = 0; f < n; f++){
		vector<int> z(ord.begin() + f*m, ord.begin() + (f+1) * m);
		sort(z.begin(), z.end(), [&](int x, int y){
			return tie(a[x], x) < tie(a[y], y);
		});
		for(int i = 0; i < m; i++){
			for(int j = i+1; j < m; j++){
				if(z[i] > z[j]){
					inv++;
				}
			}
		}
	}
	cout << inv << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}