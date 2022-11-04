#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n;
ll p, q, b;

ll gcd (ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

int main () {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    
    scanf("%d ", &n);
    while (n--) {
		scanf("%I64d %I64d %I64d", &p, &q, &b);

		ll d = gcd(p, q);
		p /= d;
		q /= d;

		if (q == 1) {
			printf("Finite\n");
			continue;
		}

		d = gcd(q, b);
		while (q > 1 && d > 1) {
			while (q % d == 0)
				q /= d;
			d = gcd(q, b);
		}

		if (q == 1)
			printf("Finite\n");
		else
			printf("Infinite\n");
	}

    return 0;
}