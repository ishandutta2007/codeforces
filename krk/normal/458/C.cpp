#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 100005;
const int Maxm = 65536;
const int Maxl = 10004;
const int Inf = 2000000000;

struct node {
	int sum, cnt;
	node(int sum = 0, int cnt = 0): sum(sum), cnt(cnt) {}
};

int n;
vector <int> byperson[Maxn];
vector <int> bypower[Maxn];
int votes;
int C;
node st[Maxm];
int res = Inf;

void Update(int v, int l, int r, int x, int dsum, int dcnt)
{
	st[v].sum += dsum; st[v].cnt += dcnt;
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) Update(2 * v, l, m, x, dsum, dcnt);
		else Update(2 * v + 1, m + 1, r, x, dsum, dcnt);
	}
}

int Get(int v, int l, int r, int hm)
{
	if (hm <= 0) return 0;
	if (l == r) return hm * (st[v].sum / st[v].cnt);
	else {
		int m = l + r >> 1;
		if (hm <= st[2 * v].cnt) return Get(2 * v, l, m, hm);
		else return st[2 * v].sum + Get(2 * v + 1, m + 1, r, hm - st[2 * v].cnt);
	}
}

int main()
{
	scanf("%d", &n);
	while (n--) {
		int a, b; scanf("%d %d", &a, &b);
		byperson[a].push_back(b);
		votes++;
		if (a) Update(1, 0, Maxl - 1, b, b, 1);
	}
	for (int i = 1; i < Maxn; i++) {
		sort(byperson[i].begin(), byperson[i].end());
		for (int j = 1; j <= byperson[i].size(); j++)
			bypower[j].push_back(byperson[i][byperson[i].size() - j]);
	}
	for (int i = votes; i >= byperson[0].size(); i--) {
		for (int j = 0; j < bypower[i].size(); j++) {
			C += bypower[i][j]; byperson[0].push_back(0);
			Update(1, 0, Maxl - 1, bypower[i][j], -bypower[i][j], -1);
		}
		res = min(res, C + Get(1, 0, Maxl - 1, i - int(byperson[0].size())));
	}
	printf("%d\n", res);
	return 0;
}