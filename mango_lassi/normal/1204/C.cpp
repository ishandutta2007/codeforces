#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9 + 7;

const int N = 100;
const int M = 1e6;
int dist[N][N];
int seq[M];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		for (int j = 0; j < n; ++j) {
			if (str[j] == '1') dist[i][j] = 1;
			else dist[i][j] = INF;
		}
		dist[i][i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		for (int a = 0; a < n; ++a) {
			for (int b = 0; b < n; ++b) {
				dist[a][b] = min(dist[a][b], dist[a][i] + dist[i][b]);
			}
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> seq[i];
		--seq[i];
	}

	vector<int> res = {seq[0]};
	for (int j = 0; j+1 < m;) {
		int i = j;
		while((j+1 < m) && (dist[seq[i]][seq[j+1]] >= j+1-i)) ++j;
		res.push_back(seq[j]);
	}

	cout << res.size() << '\n';
	for (auto v : res) cout << v+1 << ' '; cout << '\n';
}