#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int lim = 2000000007;

vector <int> seq;
int T;
int n;

int main()
{
	for (ll i = 3; i * i <= lim; i += 2)
		seq.push_back((i * i + 1) / 2);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int ind = upper_bound(seq.begin(), seq.end(), n) - seq.begin();
		printf("%d\n", ind);
	}
    return 0;
}