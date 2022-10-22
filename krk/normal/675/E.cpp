#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, a[Maxn];
deque <int> D;
ll sum[Maxn];
ll res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
		scanf("%d", &a[i]);
	D.push_front(n - 1); sum[n - 1] = res = 1;
	for (int i = n - 2; i >= 1; i--) {
		int ind = upper_bound(D.begin(), D.end(), a[i]) - D.begin() - 1;
		sum[i] = ll(n - i) + sum[D[ind]] - ll(a[i] - D[ind]);
		res += sum[i];
		while (!D.empty() && a[i] >= a[D.front()]) D.pop_front();
		D.push_front(i);
	}
	printf("%I64d\n", res);
	return 0;
}