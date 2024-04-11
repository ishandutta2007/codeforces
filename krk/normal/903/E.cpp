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

const int Maxn = 5005;
const int Maxl = 26;

int k, n;
string S[Maxn];
bool was[Maxl];

bool Check(const string &my, const string &his, bool rep)
{
	vector <int> seq;
	for (int i = 0; i < n; i++)
		if (my[i] != his[i]) seq.push_back(i);
	if (seq.size() == 0) return rep;
	return seq.size() == 2 && my[seq[0]] == his[seq[1]] && my[seq[1]] == his[seq[0]];
}

int main()
{
	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; i++)
		cin >> S[i];
	int j = 1;
	while (j < k && S[0] == S[j]) j++;
	if (j >= k) {
		swap(S[0][0], S[0][1]);
		printf("%s\n", S[0].c_str());
		return 0;
	}
	vector <int> V;
	for (int i = 0; i < n; i++)
		if (S[0][i] != S[j][i]) V.push_back(i);
	if (V.size() == 1 || V.size() > 4) { printf("-1\n"); return 0; }
	string my = S[0];
	bool rep = false;
	for (int i = 0; i < my.length(); i++) {
		rep |= was[my[i] - 'a'];
		was[my[i] - 'a'] = true;
	}
	bool ok = true;
	for (int l = 0; l < k && ok; l++)
		ok = Check(my, S[l], rep);
	if (ok) { printf("%s\n", my.c_str()); return 0; }
	for (int i = 0; i < V.size(); i++)
		for (int j = 0; j < n; j++) if (V[i] != j) {
			swap(my[V[i]], my[j]);
			ok = true;
			for (int l = 0; l < k && ok; l++)
				ok = Check(my, S[l], rep);
			if (ok) { printf("%s\n", my.c_str()); return 0; }
			swap(my[V[i]], my[j]);
		}
	printf("-1\n");
	return 0;
}