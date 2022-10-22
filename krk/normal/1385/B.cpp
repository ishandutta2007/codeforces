#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;

int T;
int n;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		vector <int> res;
		set <int> S;
		for (int i = 0; i < 2 * n; i++) {
			int a; scanf("%d", &a);
			if (S.count(a) == 0) res.push_back(a);
			S.insert(a);
		}
		for (int i = 0; i < res.size(); i++)
			printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	}
    return 0;
}