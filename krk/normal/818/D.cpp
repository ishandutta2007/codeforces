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

const int Maxn = 1000001;

int n, A;
bool er[Maxn];
set <ii> S;
int cnt[Maxn];
int cntA;

int main()
{
	scanf("%d %d", &n, &A); er[A] = true;
	for (int i = 1; i < Maxn; i++) if (!er[i])
		S.insert(ii(cnt[i], i));
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		if (a == A) {
			cntA++;
			while (!S.empty() && S.begin()->first < cntA) {
				er[S.begin()->second] = true; S.erase(S.begin());
			}
		} else if (!er[a]) {
			S.erase(ii(cnt[a], a));
			cnt[a]++;
			S.insert(ii(cnt[a], a));
		}
	}
	if (S.empty()) printf("-1\n");
	else printf("%d\n", S.begin()->second);
	return 0;
}