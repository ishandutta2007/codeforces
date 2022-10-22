#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int a[Maxn];
multiset <ll> S;
ll zer;
int t[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
		S.insert(zer + a[i]);
		ll res = 0;
		while (!S.empty() && *S.begin() - zer <= t[i]) {
			res += *S.begin() - zer; S.erase(S.begin());
		}
		res += ll(S.size()) * t[i];
		zer += t[i];
		printf("%I64d%c", res, i + 1 < n? ' ': '\n');
	}
	return 0;
}