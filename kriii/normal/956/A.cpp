#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

int N, M;

int main()
{
	scanf("%d %d", &N, &M);
	set<long long> S;
	while (N--) {
		char V[55];
		scanf("%s", V);
		long long x = 0;
		for (int i = 0; i < M; i++) if (V[i] == '#') x |= 1ll << i;
		S.insert(x);
	}
	for (auto x : S) for (auto y : S) if (x < y && (x & y)) {
		puts("No");
		return 0;
	}
	puts("Yes");
	return 0;
}