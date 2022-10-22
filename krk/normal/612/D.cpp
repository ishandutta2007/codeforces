#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000005;

int n, k;
int l[Maxn], r[Maxn];
vector <ii> seq;
vector <ii> res;

int main() 
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &l[i], &r[i]);
		seq.push_back(ii(l[i], -1));
		seq.push_back(ii(r[i], 1));
	}
	sort(seq.begin(), seq.end());
	int cur = 0;
	for (int i = 0; i < seq.size(); i++) {
		cur -= seq[i].second;
		if (cur >= k)
			if (res.empty() || res.back().second < seq[i].first) res.push_back(ii(seq[i].first, seq[i + 1].first));
			else res.back().second = max(res.back().second, seq[i + 1].first);
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}