#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int N = 12;
const int NN = 1<<N;
const int Q = 5 * (int)1e5;
const int V = 100;

vector<pair<int, int>> ques[NN];
int counts[NN];
int vals[NN];
int weights[N];
int ans[Q];
int col[V + 1];

int getInd(const string& str) {
	int v = 0;
	for (int j = 0; j < str.size(); ++j) {
		if (str[j] == '1') v += (1<<j);
	}
	return v;
}

int getVal(const string& str) {
	return vals[getInd(str)];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < n; ++i) cin >> weights[i];
	
	int nn = (1<<n);
	for (int i = 0; i < nn; ++i) {
		for (int j = 0; j < n; ++j) {
			if (0 == (i & (1<<j))) vals[i] += weights[j];
		}
	}

	for (int i = 0; i < m; ++i) {
		string str;
		cin >> str;
		++counts[getInd(str)];
	}
	for (int i = 0; i < q; ++i) {
		string str;
		cin >> str;
		int k;
		cin >> k;
		ques[getInd(str)].push_back({k, i});
	}
	for (int i = 0; i < nn; ++i) {
		if (ques[i].empty()) continue;
		for (int j = 0; j <= V; ++j) col[j] = 0;
		for (int j = 0; j < nn; ++j) {
			int v = vals[i ^ j];
			if (v <= V) col[v] += counts[j];
		}
		/*
		cerr << i << ": ";
		for (int j = 0; j <= V; ++j) if (col[j]) cerr << "{" << j << ' ' << col[j] << "} ";
		cerr << '\n';
		*/
		for (int j = 1; j <= V; ++j) col[j] += col[j-1];
		for (int j = 0; j < ques[i].size(); ++j) {
			ans[ques[i][j].second] = col[ques[i][j].first];
		}
	}
	for (int i = 0; i < q; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}