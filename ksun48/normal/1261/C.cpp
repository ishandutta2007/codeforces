#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > psums(vector<vector<int> > a){
	int n = (int)a.size();
	int m = (int)a[0].size();
	vector<vector<int> > x(n+1, vector<int>(m+1, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			x[i+1][j+1] = x[i+1][j] + x[i][j+1] - x[i][j] + a[i][j];
		}
	}
	return x;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
			cin >> c;
			a[i][j] = (c == 'X');
		}
	}
	vector<vector<int> > asums = psums(a);
	int s = -1;
	int e = min(m, n) + 1;
	vector<vector<int> > saved_res;
	while(s + 1 < e){
		int mid = (s + e) / 2;
		int len = mid * 2 + 1;
		vector<vector<int> > res(n+1, vector<int>(m+1, 0));
		for(int i = 0; i + len <= n; i++){
			for(int j = 0; j + len <= m; j++){
				int cnt = asums[i+len][j+len] - asums[i+len][j] - asums[i][j+len] + asums[i][j];
				res[i][j] = (cnt == len * len);
			}
		}
		vector<vector<int> > rsums = psums(res);
		bool works = true;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				int ai = max(i+1 - len, 0);
				int aj = max(j+1 - len, 0);
				int cnt = rsums[i+1][j+1] - rsums[i+1][aj] - rsums[ai][j+1] + rsums[ai][aj];
				if((cnt > 0) != a[i][j]){
					works = false;
				}
			}
		}
		if(works){
			s = mid;
			saved_res = res;
		} else {
			e = mid;
		}
	}
	cout << s << '\n';
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i >= s && j >= s && saved_res[i-s][j-s]){
				cout << 'X';
			} else {
				cout << '.';
			}
		}
		cout << '\n';
	}
}