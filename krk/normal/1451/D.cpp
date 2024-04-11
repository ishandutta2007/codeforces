#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

int main()
{
	scanf("%d", &T);
	while (T--) {
		ll n, k; scanf("%I64d %I64d", &n, &k);
		ll a = 0, b = 0;
		string win1 = "Ashish", win2 = "Utkarsh";
		while (true) {
			if (k * k * (a + 1) * (a + 1) + k * k * a * a <= n * n) {
				swap(win1, win2);
			} else break;
			if (k * k * (a + 1) * (a + 1) + k * k * (a + 1) * (a + 1) <= n * n) {
				swap(win1, win2);
				a++;
			} else break;
		}
		printf("%s\n", win2.c_str());
	}
    return 0;
}