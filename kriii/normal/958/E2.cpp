#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

struct line {
	line(long long l_, int i_) { l = l_, i = i_; }
	long long l; int i;
	bool operator <(const line t) const { return l > t.l; }
};

int N, K, L[500010];
int Prev[500010], Next[500010]; long long Cost[500010]; bool Chk[500010];

void proc()
{
	int K,N;
	scanf("%d %d", &K, &N);

	for (int i = 0; i < N; i++) scanf("%d", &L[i]);
	sort(L, L + N); N--;

	long long Sum = 0;
	priority_queue<line> Q;

	for (int i = 1; i <= N; i++) {
		Prev[i] = i - 1;
		Next[i] = i + 1;
		Cost[i] = (L[i]-L[i-1]);
		Chk[i] = 0;
		Q.push(line(Cost[i], i));
	}
	Cost[0] = Cost[N + 1] = 1e18;

	while (!Q.empty() && K--) {
		while (Chk[Q.top().i]) Q.pop();
		int i = Q.top().i; Q.pop();
		Sum += Cost[i]; Cost[i] *= -1;

		Chk[Prev[i]] = 1;
		Cost[i] += Cost[Prev[i]];
		Next[Prev[Prev[i]]] = i;
		Prev[i] = Prev[Prev[i]];
		Chk[Next[i]] = 1;
		Cost[i] += Cost[Next[i]];
		Prev[Next[Next[i]]] = i;
		Next[i] = Next[Next[i]];

		Q.push(line(Cost[i], i));
	}
	printf("%lld\n", Sum);
}

int main()
{
#ifdef __LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	proc();
	return 0;
}