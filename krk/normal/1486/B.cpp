#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		vector <int> X, Y;
		for (int i = 0; i < n; i++) {
			int x, y; scanf("%d %d", &x, &y);
			X.push_back(x);
			Y.push_back(y);
		}
		sort(X.begin(), X.end());
		sort(Y.begin(), Y.end());
		int a, b;
		if (X.size() % 2) a = 1;
		else a = X[X.size() / 2] - X[X.size() / 2 - 1] + 1;
		if (Y.size() % 2) b = 1;
		else b = Y[Y.size() / 2] - Y[Y.size() / 2 - 1] + 1;
		printf("%I64d\n", ll(a) * b);
	}
    return 0;
}