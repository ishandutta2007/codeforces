#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxm = 500005;

int mx[Maxm];
int n, q;
int a[Maxn];
bool is[Maxn];
int cur[Maxm];
vector <int> my;
ll res;

void Gen(int lvl, int has, int tk, bool fl)
{
	if (lvl == my.size()) {
		if (fl) cur[has]--;
		if (fl ^ (tk % 2 != 0)) res -= cur[has];
		else res += cur[has];
		if (!fl) cur[has]++;
	} else {
		Gen(lvl + 1, has, tk, fl);
		Gen(lvl + 1, has * my[lvl], tk + 1, fl);
	}
}

int main()
{
	for (int i = 2; i < Maxm; i++) if (mx[i] == 0)
		for (int j = i; j < Maxm; j += i)
			mx[j] = i;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	while (q--) {
		int x; scanf("%d", &x);
		my.clear();
		int num = a[x];
		while (num > 1) {
			int pr = mx[num];
			if (my.empty() || my.back() != pr) my.push_back(pr);
			num /= pr; 
		}
		Gen(0, 1, 0, is[x]); is[x] = !is[x];
		printf("%I64d\n", res);
	}
	return 0;
}