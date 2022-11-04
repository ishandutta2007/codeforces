#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n, a[100005], c[100005] = {0};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill(c, c+100005, 0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		c[a[i]]++;
	}

	for (int i = 1; i <= 1e5; i++) {
		if (c[i] % 2) {
			cout << "Conan" << endl;
			return 0;
		}
	}

	cout << "Agasa" << endl;

	return 0;
}