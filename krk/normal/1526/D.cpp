#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxd = 4;
const string lets = "ANTO";

char tmp[Maxn];
int T;
string s;
vector <int> seq[Maxd];
int a[Maxn];
ll res;
char ans[Maxn];
int BIT[Maxn];

void Clear()
{
	fill(BIT, BIT + int(s.length()) + 1, 0);
}

void Insert(int x)
{
	for (int i = x + 1; i > 0; i -= i & -i)
		BIT[i]++;
}

int Get(int x)
{
	int res = 0;
	for (int i = x + 1; i <= s.length(); i += i & -i)
		res += BIT[i];
	return res;
}

void Check()
{
	Clear();
	ll cand = 0;
	for (int i = 0; i < s.length(); i++) {
		cand += Get(a[i]);
		Insert(a[i]);
	}
	if (cand > res) {
		res = cand;
		for (int i = 0; i < s.length(); i++)
			ans[i] = s[a[i]];
	}
}

void Read(string &s)
{
	scanf("%s", tmp);
	s = tmp;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		Read(s);
		for (int i = 0; i < Maxd; i++)
			seq[i].clear();
		for (int i = 0; i < s.length(); i++) {
			int ind = lets.find(s[i]);
			seq[ind].push_back(i);
		}
		vector <int> perm = {0, 1, 2, 3};
		res = -1;
		do {
			int pnt = 0;
			for (int i = 0; i < perm.size(); i++)
				for (int j = 0; j < seq[perm[i]].size(); j++)
					a[pnt++] = seq[perm[i]][j];
			Check();
		} while (next_permutation(perm.begin(), perm.end()));
		ans[s.length()] = '\0';
		printf("%s\n", ans);
	}
    return 0;
}