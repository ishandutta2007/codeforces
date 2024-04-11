#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int>(m));
	vector<int> rowmax(n, 0);
	vector<int> colmax(m, 0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			rowmax[i] = max(rowmax[i], a[i][j]);
			colmax[j] = max(colmax[j], a[i][j]);
		}
	}
	sort(rowmax.begin(), rowmax.end());
	sort(colmax.begin(), colmax.end());
	vector<vector<int> > b(n, vector<int>(m));
	rowmax.push_back(1e8);
	colmax.push_back(1e8);
	int ri = 0;
	int ci = 0;
	vector<int> used(n*m+1, 0);
	while(ri < n && ci < m){
		int A = min(rowmax[ri], colmax[ci]);
		b[ri][ci] = A;
		used[A] = 1;
		if(rowmax[ri] == A) ri++;
		if(colmax[ci] == A) ci++;
	}
	ri = 0;
	ci = 0;
	used[0] = 1;
	int cur = 0;
	while(ri < n && ci < m){
		int A = min(rowmax[ri], colmax[ci]);
		b[ri][ci] = A;
		for(int j = m-1; j >= 0; j--){
			if(b[ri][j] == 0){
				while(used[cur]) cur++;
				b[ri][j] = cur;
				used[cur] = 1;
			}
		}
		for(int j = n-1; j >= 0; j--){
			if(b[j][ci] == 0){
				while(used[cur]) cur++;
				b[j][ci] = cur;
				used[cur] = 1;
			}
		}
		if(rowmax[ri] == A) ri++;
		if(colmax[ci] == A) ci++;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << b[i][j] << ' ';
		}
		cout << '\n';
	}
}