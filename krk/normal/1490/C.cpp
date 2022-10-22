#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll x;
vector <ll> cubes;

int main()
{
	for (int i = 1; i <= 10000; i++)
		cubes.push_back(ll(i) * i * i);
	scanf("%d", &T);
	while (T--) {
		scanf("%I64d", &x);
		bool ok = false;
		for (int i = 0; i < cubes.size() && cubes[i] < x; i++) {
			int ind = lower_bound(cubes.begin(), cubes.end(), x - cubes[i]) - cubes.begin();
			if (ind < cubes.size() && cubes[ind] + cubes[i] == x) { ok = true; break; }
		}
		printf("%s\n", ok? "YES": "NO");
	}
    return 0;
}