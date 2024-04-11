#include <bits/stdc++.h>
using namespace std;
 
typedef long double ld;
typedef long long ll;
 
const int Maxb = 61;
const ll lim = 1000000000000000000ll;

vector <ll> V[Maxb];
int T;
ll n;
ll cnt[Maxb];
 
int main()
{
	for (int i = 1; i <= 1000000; i++) {
		ll num = ll(i) * i;
		for (int j = 3; j < Maxb; j++)
			if (num <= lim / i) {
				num *= i;
				V[j].push_back(num);
			} else break;
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%I64d", &n);
		for (int i = Maxb - 1; i > 0; i--) {
			ll num;
			if (i == 1) num = n;
			else if (i == 2) {
				ll a = sqrt(ld(n));
				while (a * a <= n) a++;
				while (a * a > n) a--;
				num = a;
			} else num = upper_bound(V[i].begin(), V[i].end(), n) - V[i].begin();
			cnt[i] = num - 1;
			for (int j = i + i; j < Maxb; j += i)
				cnt[i] -= cnt[j];
		}
		printf("%I64d\n", cnt[1]);
	}
    return 0;
}