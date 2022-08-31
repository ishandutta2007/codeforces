#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int>(m));
	vector<vector<int> > b(n, vector<int>(m));
	for(auto& x : a) for(auto& y : x) cin >> y;
	for(auto& x : b) for(auto& y : x) cin >> y;
	vector<int> nd(m, 0);
	for(int j = 0; j < m; j++){
		for(int i = 0; i+1 < n; i++){
			if(b[i][j] > b[i+1][j]) nd[j]++;
		}
	}
	vector<bool> done(n-1, false);
	vector<int> can_sort;
	for(int j = 0; j < m; j++){
		if(nd[j] == 0) can_sort.push_back(j);
	}
	int s = 0;
	while(s < (int)can_sort.size()){
		int j = can_sort[s];
		s++;
		for(int i = 0; i+1 < n; i++){
			if(done[i]) continue;
			assert(b[i][j] <= b[i+1][j]);
			if(b[i][j] < b[i+1][j]){
				done[i] = true;
				for(int j2 = 0; j2 < m; j2++){
					if(b[i][j2] > b[i+1][j2]){
						nd[j2]--;
						if(nd[j2] == 0) can_sort.push_back(j2);
					}
				}
			}
		}
	}
	reverse(can_sort.begin(), can_sort.end());
	vector<int> arr(n);
	for(int i = 0; i < n; i++) arr[i] = i;
	for(int j : can_sort){
		stable_sort(arr.begin(), arr.end(), [&](int x, int y){ return a[x][j] < a[y][j]; });
	}
	for(int i = 0; i < n; i++){
		if(a[arr[i]] != b[i]){
			cout << -1 << '\n';
			return 0;
		}
	}
	cout << can_sort.size() << '\n';
	for(int x : can_sort){
		cout << x+1 << ' ';
	}
	cout << '\n';
}