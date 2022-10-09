 #include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1010
int a, b;
int main() {
	cin >> a >> b;
	int result = 0;
	for (int i=1; i<=1000000; ++i) {
		if (a > b) swap(a, b);
		++result;
		a += 1;
		b -= 2;
		if (b == 0) OUT(result);
		if (b < 0) OUT(result - 1);
	}
}