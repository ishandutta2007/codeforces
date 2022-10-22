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
const int Maxn = 100005;

char str[Maxn];
int n;
string s;
bool was[Maxl], gwas[Maxl];
vector <int> aft[Maxl], bef[Maxl];
string res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str); s = str;
		fill(was, was + Maxl, false);
		for (int j = 0; j < s.length(); j++) {
			if (was[s[j] - 'a']) { printf("NO\n"); return 0; }
			else was[s[j] - 'a'] = true;
			gwas[s[j] - 'a'] = true;
			if (j > 0) {
				int a = s[j - 1] - 'a', b = s[j] - 'a';
				aft[a].push_back(b); bef[b].push_back(a);
			}
		}
	}
	for (int i = 0; i < Maxl; i++) {
		if (!aft[i].empty()) {
			sort(aft[i].begin(), aft[i].end());
			if (aft[i][0] != aft[i].back()) { printf("NO\n"); return 0; }
		}
		if (!bef[i].empty()) {
			sort(bef[i].begin(), bef[i].end());
			if (bef[i][0] != bef[i].back()) { printf("NO\n"); return 0; }
		}
	}
	for (int i = 0; i < Maxl; i++) if (gwas[i] && bef[i].empty()) {
		int v = i;
		while (v != -1) {
			gwas[v] = false; res += string(1, 'a' + v);
			v = aft[v].empty()? -1: aft[v][0];
		}
	}
	for (int i = 0; i < Maxl; i++) 
		if (gwas[i]) { printf("NO\n"); return 0; }
	printf("%s\n", res.c_str());
	return 0;
}