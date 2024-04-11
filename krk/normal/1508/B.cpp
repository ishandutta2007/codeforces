#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n;
ll k;

ll Get(int n) { return n == 0? 1: 1ll << ll(n - 1); }

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %I64d", &n, &k);
		if (n <= 60 && (1ll << ll(n - 1)) < k) { printf("-1\n"); continue; }
		vector <int> seq;
		int zer = 1;
		while (n - zer > 60) { seq.push_back(zer); zer++; }
		while (zer <= n) {
			int sub = 0;
			while (Get(n - zer - sub) < k) { k -= Get(n - zer - sub); sub++; }
			for (int i = sub; i >= 0; i--)
				seq.push_back(zer + i);
			zer += sub + 1;
		}
		for (int i = 0; i < seq.size(); i++)
			printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
	}
    return 0;
}