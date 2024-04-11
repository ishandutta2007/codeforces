#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

char str[Maxn];
int slen;
set <int> Z, O;
vector <vector <int> > seq;

int main()
{
	scanf("%s", str + 1); slen = strlen(str + 1);
	int res = 0;
	for (int i = 1; i <= slen; i++)
		if (str[i] == '1') { O.insert(i); res--; }
		else { Z.insert(i); res++; }
	for (int i = 0; i < res; i++) {
		bool zer = true;
		int from = 0;
		vector <int> tmp;
		set <int>::iterator it;
		while (true) {
			if (zer) {
				it = Z.upper_bound(from);
				if (it == Z.end()) break;
				from = *it; Z.erase(it); tmp.push_back(from);
			} else {
				it = O.upper_bound(from);
				if (it == O.end()) break;
				from = *it; O.erase(it); tmp.push_back(from);
			}
			zer = !zer;
		}
		if (!tmp.empty() && str[tmp.back()] == '1') {
			O.insert(tmp.back()); tmp.pop_back();
		}
		if (tmp.empty()) { printf("-1\n"); return 0; }
		seq.push_back(tmp);
	}
	if (O.size() || Z.size()) { printf("-1\n"); return 0; }
	printf("%d\n", seq.size());
	for (int i = 0; i < seq.size(); i++) {
		printf("%d", seq[i].size());
		for (int j = 0; j < seq[i].size(); j++)
			printf(" %d", seq[i][j]);
		printf("\n");
	}
	return 0;
}