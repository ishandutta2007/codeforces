#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 5005;

int T;
int n;
int S[Maxn];
ll delt[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &S[i]);
			delt[i] = 0;
		}
		ll res = 0;
		ll cur = 0;
		for (int i = 0; i < n; i++) {
			cur += delt[i];
			ll me = cur;
			if (me < S[i] - 1) { res += S[i] - 1 - me; me = S[i] - 1; }
			delt[i + 2]++;
			delt[min(i + S[i] + 1, n)]--;
			ll lft = me - (S[i] - 1);
			delt[i + 1] += lft;
			delt[i + 2] -= lft;
		}
		printf("%I64d\n", res);
	}
    return 0;
}