#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 10005;

int m, n;
map <string, int> ID;
string nam[Maxn];
bool has[Maxn][Maxn];
vector <int> neigh[Maxn];
short same[Maxn];

int getID(const string &s)
{
	if (!ID.count(s)) {
		int no = ID.size();
		nam[no] = s; ID[s] = no;
	}
	return ID[s];
}

void Get(int a, int b)
{
	for (int i = 0; i < neigh[b].size(); i++) {
		int c = neigh[b][i];
		if (c != a && !has[a][c]) same[c]++;
	}
}

int main()
{
	string u, v;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		int a = getID(u), b = getID(v);
		has[a][b] = has[b][a] = true;
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	n = ID.size();
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		fill(same, same + n, 0);
		for (int j = 0; j < neigh[i].size(); j++)
			Get(i, neigh[i][j]);
		int best = -1, cnt = 0;
		for (int j = 0; j < n; j++) 
			if (i != j && !has[i][j]) {
				if (same[j] > best) { best = same[j]; cnt = 0; }
				if (same[j] == best) cnt++;
			}
		cout << nam[i] << " " << cnt << endl;
	}
	return 0;
}