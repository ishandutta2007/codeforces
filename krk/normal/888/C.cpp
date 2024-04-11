#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxl = 26;

string s;
vector <int> V[Maxl];
int res = 1000000000;

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		V[s[i] - 'a'].push_back(i);
	for (int i = 0; i < Maxl; i++) if (!V[i].empty()) {
		int cand = V[i][0] + 1;
		for (int j = 1; j < V[i].size(); j++)
			cand = max(cand, V[i][j] - V[i][j - 1]);
		cand = max(cand, int(s.length()) - V[i].back());
		res = min(res, cand);
	}
	printf("%d\n", res);
	return 0;
}