#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> p(n);
	for(int i = 0; i < n; i++){
		cin >> p[i];
		p[i]--;
	}
	if(n == 1){
		cout << -1 << '\n';
		return;
	}
	vector<int> used(n);
	vector<int> q(n);
	for(int i = 0; i < n; i++){
		int a = 0;
		while(a < n && (used[a] || a == p[i])) a++;
		if(a == n) a = p[i];
		q[i] = a;
		used[a] = 1;
	}
	do {
		bool works = true;
		for(int i = 0; i < n; i++){
			if(p[i] == q[i]) works = false;
		}
		if(works){
			for(int i = 0; i < n; i++){
				cout << (q[i] + 1) << " \n"[i == n-1];
			}
			return;
		}
	} while (next_permutation(q.begin(), q.end()));
	cout << -1 << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}