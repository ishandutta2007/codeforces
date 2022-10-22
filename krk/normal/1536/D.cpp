#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Inf = 2000000007;

int T;
int n;
int b[Maxn];

bool Solve()
{
	set <int> S;
	S.insert(-Inf); S.insert(b[0]); S.insert(Inf);
	for (int i = 1; i < n; i++) {
		auto it = S.find(b[i - 1]);
		if (b[i] < b[i - 1]) {
			it--;
			if (b[i] < *it) return false;
		} else if (b[i] > b[i - 1]) {
			it++;
			if (*it < b[i]) return false;
		}
		S.insert(b[i]);
	}
	return true;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &b[i]);
		printf("%s\n", Solve()? "YES": "NO");
	}
    return 0;
}