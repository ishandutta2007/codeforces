#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000005;
const int Maxd = 3;

char tmp[Maxn];
int T;
int n;
string s[Maxd];
char res[Maxn];
int rlen;

void Read(string &s)
{
	scanf("%s", tmp);
	s = tmp;
}

ii Get(const string &a)
{
	ii res = ii(0, 0);
	for (int i = 0; i < a.length(); i++)
		if (a[i] == '0') res.first++;
		else res.second++;
	return res;
}

void Solve(const string &a, const string &b, char nd)
{
	int lft = n;
	int i = 0, j = 0;
	rlen = 0;
	for (int k = 0; k < n; k++) {
		while (a[i] != nd) res[rlen++] = a[i++];
		while (b[j] != nd) res[rlen++] = b[j++];
		res[rlen++] = nd;
		i++; j++;
	}
	while (i < a.length()) res[rlen++] = a[i++];
	while (j < b.length()) res[rlen++] = b[j++];
	res[rlen] = '\0';
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < Maxd; i++)
			Read(s[i]);
		bool ok = false;
		for (int i = 0; i < Maxd && !ok; i++)
			for (int j = i + 1; j < Maxd && !ok; j++) {
				ii a = Get(s[i]), b = Get(s[j]);
				if (a.first >= n && b.first >= n) {
					Solve(s[i], s[j], '0');
					ok = true;
				} else if (a.second >= n && b.second >= n) {
					Solve(s[i], s[j], '1');
					ok = true;
				}
			}
		assert(ok);
		printf("%s\n", res);
	}
    return 0;
}