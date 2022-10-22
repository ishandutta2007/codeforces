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
		bool ok = true;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			sum += a;
			if (sum >= i) sum -= i;
			else ok = false; 
		}
		printf("%s\n", ok? "YES": "NO");
	}
    return 0;
}