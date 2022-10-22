#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 105;

int n, m;
int a[Maxn];
bool taken[Maxn];
vector <int> A;
ll cur;

bool Check(int from)
{
	ll res = cur;
	for (int i = from; i >= 0; i--)
		if (res < A[i]) return false;
		else res += res;
	return true;
}

ll Get(int from)
{
	ll res = cur;
	for (int i = from; i >= 0; i--)
		res += res;
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	while (m--) {
		int b; scanf("%d", &b);
		taken[b] = true;
	}
	for (int i = 1; i <= n; i++)
		if (taken[i]) A.push_back(a[i]);
		else cur += a[i];
	sort(A.begin(), A.end());
	for (int i = int(A.size()) - 1; i >= 0; i--) {
		if (Check(i)) { printf("%I64d\n", Get(i)); return 0; }
		cur += A[i];
	}
	printf("%I64d\n", Get(-1));
	return 0;
}