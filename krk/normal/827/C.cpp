#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxtmp = 200005;
const int Maxl = 11;
const int Maxd = 4;
const string st = "ATGC";

char tmp[Maxtmp];
string s;
int n;
vector <int> BIT[Maxl][Maxl][Maxd];

void Add(vector <int> &BIT, int x, int add)
{
	x++;
	for (int i = x; i < BIT.size(); i += i & -i)
		BIT[i] += add;
}

int Get(const vector <int> &BIT, int x)
{
	x++;
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

void Read(string &s)
{
	scanf("%s", tmp); s = tmp;
}

int main()
{
	Read(s); n = s.length();
	for (int i = 1; i < Maxl; i++) {
		int len = (n - 1) / i + 1;
		for (int j = 0; j < i; j++)
			for (int k = 0; k < Maxd; k++)
				BIT[i][j][k].resize(len + 1, 0);
	}
	for (int i = 0; i < n; i++) {
		int p = st.find(s[i]);
		for (int j = 1; j < Maxl; j++)
			Add(BIT[j][i % j][p], i / j, 1);
	}
	int q; scanf("%d", &q);
	while (q--) {
		int typ; scanf("%d", &typ);
		if (typ == 1) {
			int x; char c; scanf("%d %c", &x, &c); x--;
			int p = st.find(s[x]);
			for (int j = 1; j < Maxl; j++)
				Add(BIT[j][x % j][p], x / j, -1);
			s[x] = c;
			p = st.find(s[x]);
			for (int j = 1; j < Maxl; j++)
				Add(BIT[j][x % j][p], x / j, 1);
		} else {
			int l, r; string e; scanf("%d %d", &l, &r); Read(e); l--; r--;
			int res = 0;
			for (int i = 0; i < e.length() && l + i <= r; i++) {
				int p = st.find(e[i]);
				int off = (l + i) % e.length();
				int lef = (l + i) / e.length();
				int rig = r / e.length();
				if (rig * e.length() + off > r) rig--;
				res += Get(BIT[e.length()][off][p], rig);
				res -= Get(BIT[e.length()][off][p], lef - 1);
			}
			printf("%d\n", res);
		}
	}
	return 0;
}