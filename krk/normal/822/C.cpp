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

const int Inf = 2000000005;
const int Maxn = 400005;

int n, x;
int L[Maxn], R[Maxn], C[Maxn];
vector <ii> seq;
int res = Inf;
int has[Maxn];

int main()
{
	scanf("%d %d", &n, &x);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &L[i], &R[i], &C[i]);
		seq.push_back(ii(L[i], -i));
		seq.push_back(ii(R[i], i));
	}
	sort(seq.begin(), seq.end());
	fill(has, has + Maxn, -1);
	for (int i = 0; i < seq.size(); i++) {
		int ind = seq[i].second;
		if (ind < 0) {
			ind = -ind;
			int len = R[ind] - L[ind] + 1;
			if (len <= x && has[x - len] != -1)
				res = min(res, C[ind] + has[x - len]);
		} else {
			int len = R[ind] - L[ind] + 1;
			if (len <= x) has[len] = has[len] == -1? C[ind]: min(has[len], C[ind]);
		}
	}
	if (res >= Inf) printf("-1\n");
	else printf("%d\n", res);
	return 0;
}