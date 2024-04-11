#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> been;
vector<vector<int> > sorted;
vector<vector<pair<int, bool> > > graph;

void dfs(int index) {
	been[index] = 1;
	for (int i = 0; i < graph[index].size(); i++)
		if (!been[graph[index][i].first])
			dfs(graph[index][i].first);
	sorted[sorted.size() - 1].push_back(index);
}

bool dfs2(int index) {
	bool res = false;
	been[index] = 1;
	for (int i = 0; i < graph[index].size(); i++)
		if (graph[index][i].second) {
			if (been[graph[index][i].first] == 1)
				res = true;
			if (!been[graph[index][i].first])
				res |= dfs2(graph[index][i].first);
		}
	been[index] = 2;
	return res;
}

int main() {
	/*ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");*/

	int n, m, i, j, a, b;
	cin >> n >> m;
	graph = vector<vector<pair<int, bool> > >(n);
	vector<bool> leads(n, true);
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(make_pair(b, true));
		graph[b].push_back(make_pair(a, false));
		leads[b] = false;
	}
	
	been = vector<int>(n);
	for (i = 0; i < n; i++)
		if (!been[i]) {
			sorted.push_back(vector<int>());
			dfs(i);
		}

	vector<int> which(n);
	for (i = 0; i < sorted.size(); i++)
		for (j = 0; j < sorted[i].size(); j++)
			which[sorted[i][j]] = i;
	vector<int> leadwho(sorted.size(), -1);

	for (i = 0; i < n; i++) {
		been[i] = 0;
		if (leads[i])
			leadwho[which[i]] = i;
	}

	int res = 0;
	bool loop;
	for (i = 0; i < sorted.size(); i++) {
		loop = false;
		for (j = 0; j < sorted[i].size(); j++)
			if (!been[sorted[i][j]])
				loop |= dfs2(sorted[i][j]);
		res += sorted[i].size() - 1 + loop;
	}
	cout << res;

	return 0;
}