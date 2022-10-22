#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxm = 10000005;

vector <int> pr;
int dv[Maxm];
int T;
int n, k;
set <int> S;

int main()
{
	for (int i = 2; i < Maxm; i++) {
		if (dv[i] == 0) { dv[i] = i; pr.push_back(i); }
		for (int j = 0; j < pr.size() && pr[j] * i < Maxm; j++) {
			dv[pr[j] * i] = pr[j];
			if (i % pr[j] == 0) break;
		}
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		S.clear();
		int res = 1;
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			int got = 1;
			while (a > 1) {
				int cur = dv[a], cnt = 0;
				while (a % cur == 0) { a /= cur; cnt++; }
				if (cnt % 2) got *= cur;
			}
			if (S.find(got) != S.end()) { S.clear(); res++; }
			S.insert(got);
		}
		printf("%d\n", res);
	}
    return 0;
}