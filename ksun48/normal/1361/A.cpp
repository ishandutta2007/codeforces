#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > edges(n);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	vector<int> z(n);
	for(int i = 0; i < n; i++) cin >> z[i];
	vector<int> ord(n);
	for(int i = 0; i < n; i++) ord[i] = i;
	sort(ord.begin(), ord.end(), [&](int r, int s) { return z[r] < z[s];});
	vector<set<int> > used(n);
	for(int a : ord){
		int c = 1;
		while(used[a].count(c)) c++;
		if(c != z[a]){
			cout << -1 << '\n';
			return 0;
		}
		for(int b : edges[a]) used[b].insert(z[a]);
	}
	for(int a : ord){
		cout << a + 1 << ' ';
	}
	cout << '\n';
}