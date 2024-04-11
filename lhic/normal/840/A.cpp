#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

int n;
ll a[220000];
ll b[220000];
ll ans[220000];

vector<pair<ll, int> > vv;


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i);
	for (int i = 0; i < n; ++i)
		scanf("%lld", b + i);
	for (int i = 0; i < n; ++i)
		vv.push_back(make_pair(b[i], i));
	sort(vv.begin(), vv.end());
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < n; ++i) {
		ans[vv[i].second] = a[i];
	}
	for (int i = 0; i < n; ++i)
		printf("%lld ", ans[i]);
	printf("\n");
    return 0;
}