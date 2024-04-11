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

typedef pair <int, int> ii;

const int Maxn = 100005;

int n, k;
vector <ii> seq, res;
int a[Maxn];

int main()
{
	scanf("%d %d", &n, &k);
	seq.push_back(ii(0, n));
	for (int i = 0; i < seq.size(); i++)
		if (seq[i].first + 1 == seq[i].second) res.push_back(seq[i]);
		else if (seq.size() < k) {
			int m = seq[i].first + seq[i].second >> 1;
			seq.push_back(ii(seq[i].first, m));
			seq.push_back(ii(m, seq[i].second));
		} else res.push_back(seq[i]);
	if (seq.size() != k) printf("-1\n");
	else {
		sort(res.begin(), res.end());
		int num = n;
		int cur = num;
		for (int i = 0; i < res.size(); i++) {
			int tk = res[i].second - res[i].first;
			int ind = res[i].first;
			for (int i = num - tk + 1; i <= num; i++)
				a[ind++] = i;
			num -= tk;
		}
		for (int i = 0; i < n; i++)
			printf("%d%c", a[i], i + 1 < n? ' ': '\n');
	}
	return 0;
}