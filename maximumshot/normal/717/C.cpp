#include <bits/stdc++.h>

#define FOR(i, p, n) for(int i = p; i < n; ++i)
#define FORD(i, p, n) for(int i = p; i >= n; --i)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define RE scanf
#define WR printf

using namespace std;

typedef long long ll;
typedef long double ld;

int arr[100000];

int main() {
	int n;
	cin >> n;
	FOR(i, 0, n) RE("%d", arr + i);
	ll res = 0;
	sort(arr, arr + n);
	FOR(i, 0, n) res += (ll)arr[i] * (ll)arr[n - i - 1];
	cout << (res % 10007);

	return 0;
}