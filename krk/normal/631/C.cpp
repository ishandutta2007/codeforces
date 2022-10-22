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

const int Maxn = 200005;

int n, m;
int a[Maxn];
vector <ii> S;
int res[Maxn];

int main() 
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) {
		int t, r; scanf("%d %d", &t, &r);
		while (!S.empty() && S.back().first <= r) S.pop_back();
		S.push_back(ii(r, t));
	}
	for (int i = n - 1; i >= S[0].first; i--)
		res[i] = a[i];
	sort(a, a + S[0].first);
	int l = 0, r = S[0].first - 1;
	S.push_back(ii(0, 1));
	for (int i = 0; i + 1 < S.size(); i++)
		while (S[i].first > S[i + 1].first) {
			S[i].first--;
			if (S[i].second == 1) res[S[i].first] = a[r--];
			else res[S[i].first] = a[l++];
		}
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    return 0;
}