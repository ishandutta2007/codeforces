#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;

int T;
int n;

int F(int a, int b)
{
	if (a > b) swap(a, b);
	if (a == 1) return b <= 2? 0: Inf;
	return 1 + F(a, (b - 1) / a + 1);
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int ans = Inf, bi;
		for (int i = 1; i <= n; i++) {
			int cand = F(i, n);
			if (cand < ans) { ans = cand; bi = i; }
		}
		vector <ii> en, st;
		int a = n, b = bi;
		int inda = n, indb = bi;
		while (a > 1 && b > 1)
			if (a > b) { en.push_back(ii(inda, indb)); a = (a - 1) / b + 1; }
			else { en.push_back(ii(indb, inda)); b = (b - 1) / a + 1; }
		for (int i = 2; i <= n; i++) if (i != inda && i != indb)
			if (i == 2) {
				if (a == 2 || b == 2) st.push_back(ii(i, i + 1));
			} else st.push_back(ii(i, i + 1));
		printf("%d\n", int(st.size()) + int(en.size()));
		for (int i = 0; i < st.size(); i++)
			printf("%d %d\n", st[i].first, st[i].second);
		for (int i = 0; i < en.size(); i++)
			printf("%d %d\n", en[i].first, en[i].second);
	}
    return 0;
}