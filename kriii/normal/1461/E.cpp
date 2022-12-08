#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

set<long long> chk;

int main()
{
	long long k, l, r, t, x, y;
	scanf ("%lld %lld %lld %lld %lld %lld", &k, &l, &r, &t, &x, &y);

	while (1){
		if (k + y <= r){
			if (k + y - x < l){
				puts("No");
				break;
			}

			if (x == y){
				puts("Yes");
				break;
			}

			if (x > y){
				long long i = (k - l) / (x - y);
				k += i * (y - x);
				t -= i;
			}
			else{
				long long i = ((r - y) - k) / (y - x) + 1;
				k += i * (y - x);
				t -= i;
			}
		}
		else{
			long long i = l + y <= r ? (k - (r - y) + x - 1) / x : 1e18;
			long long j = (k - l) / x + 1;
			k -= x * min(i, j);
			t -= min(i, j);
			if (t >= 0 && k < l){
				puts("No");
				break;
			}
		}

		if (t <= 0 || chk.count(k)){
			puts("Yes");
			break;
		}
		chk.insert(k);
	}

	return 0;
}