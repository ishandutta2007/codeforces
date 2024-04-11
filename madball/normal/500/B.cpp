#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<bool> > matrix;
vector<int> comp;

void dfs(int from, int curcomp) {
	comp[from] = curcomp;
	for (int i = 0; i < matrix[from].size(); i++)
		if (matrix[from][i] && (comp[i] == -1))
			dfs(i, curcomp);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> perm(n);
	comp = vector<int>(n, -1);

	for (int i = 0; i < n; i++) {
		cin >> perm[i];
		perm[i]--;
	}
	char c;

	matrix = vector<vector<bool> >(n, vector<bool>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> c;
			matrix[i][j] = (c == '1');
		}

	int curcomp = 0;
	vector<int> tosort;
	for (int i = 0; i < n; i++)
		if (comp[i] == -1) {
			dfs(i, curcomp);
			tosort.clear();
			for (int j = 0; j < n; j++)
				if (comp[j] == curcomp)
					tosort.push_back(perm[j]);
			sort(tosort.begin(), tosort.end());
			int k = 0;
			for (int j = 0; j < n; j++)
				if (comp[j] == curcomp) {
					perm[j] = tosort[k];
					k++;
				}

			curcomp++;
		}

	for (int i = 0; i < n; i++)
		cout << perm[i] + 1 << ' ';
	return 0;
}