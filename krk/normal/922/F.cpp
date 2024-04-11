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
#include <cassert>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;

int n;
int k;
int my[Maxn];
vector <int> dv[Maxn];
vector <ii> seq;
int tot;
bool in[Maxn];
bool found;

void Gen(int from, int tot)
{
	if (tot == k)
		found = true;
	else if (from >= seq.size()) return;
	else {
		int num = seq[from].second;
		int sub = 0;
		for (int j = 0; j < dv[num].size(); j++)
			sub += in[dv[num][j]];
		for (int j = num + num; j <= n; j += num)
			sub += in[j];
		if (sub > 0 && tot - sub >= k) {
			in[num] = false;
			Gen(from + 1, tot - sub);
			if (found) return;
			in[num] = true;
		}
		Gen(from + 1, tot);
	}
}

bool Find()
{
	for (int i = 1; i <= n; i++)
		dv[i].clear();
	seq.clear();
	tot = 0;
	for (int i = 1; i <= n; i++) {
		my[i] = 0;
		in[i] = true;
		for (int j = i + i; j <= n; j += i) {
			my[i]++;
			dv[j].push_back(i);
		}
		tot += my[i];
		seq.push_back(ii(my[i], i));
	}
	sort(seq.rbegin(), seq.rend());
	if (tot < k) { printf("No\n"); return false; }
	found = false;
	Gen(0, tot);
	assert(found);
	vector <int> res;
	for (int i = 1; i <= n; i++) if (in[i])
		res.push_back(i);
	printf("Yes\n");
	printf("%d\n", int(res.size()));
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
}

int main()
{
	scanf("%d %d", &n, &k);
	Find();
	return 0;
}