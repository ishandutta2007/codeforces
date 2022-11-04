#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	string n;
	ll k, sum = 0, res = 0;
	vector<ll> cub(10);

	cin >> k >> n;

	for (char c : n) {
		cub[c-'0']++;
		sum += c - '0';
	}

	int i = 0;
	while (sum < k) {
		while (!cub[i])
			i++;
		sum += 9 - i;
		res++;
		cub[i]--;
	}

	cout << res;

	return 0;
}