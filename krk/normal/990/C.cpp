#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 800015;
const int nil = 400005;

char tmp[Maxn];
int n;
int st[Maxn], mn[Maxn];
vector <int> V[Maxn];
ll res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", tmp); int tlen = strlen(tmp);
		mn[i] = Maxn;
		for (int j = 0; j < tlen; j++) {
			if (tmp[j] == '(') st[i]++;
			else st[i]--;
			mn[i] = min(mn[i], st[i]);
		}
		V[st[i] + nil].push_back(mn[i]);
	}
	for (int i = 0; i < Maxn; i++) if (V[i].size())
		sort(V[i].begin(), V[i].end());
	for (int i = 0; i < n; i++) if (mn[i] >= 0) {
		int ost = nil - st[i];
		int add = V[ost].end() - lower_bound(V[ost].begin(), V[ost].end(), -st[i]);
		res += add;
	}
	cout << res << endl;
	return 0;
}