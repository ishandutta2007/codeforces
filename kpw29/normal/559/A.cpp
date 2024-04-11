#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
#define OUT(x) { cout << x; return 0; }
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const int inf = 1e9+9;
const int mod = 1e9+696969;
const ll INF = 1e18+3;
#define maxn 200100
const ll P = 29;
ll t[10];
int main()
{
	cin >> t[1] >> t[2] >> t[3] >> t[4] >> t[5] >> t[6];
	ll wyn = t[1] + t[2] + t[3];
	wyn *= wyn;
	ll w2 = t[1]  * t[1] + t[3] * t[3]  + t[5] * t[5];
	cout << wyn - w2;
}