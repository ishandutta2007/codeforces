#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define FOR(i, a, b) for (int i=(a); i<=(b); ++i)
#define boost ios_base::sync_with_stdio(false);
#define OUT(x) {cout << x; exit(0); }
typedef pair <int, int> PII;
typedef long long ll;
typedef unsigned int ui;
const int mod = 1e9+7;

const int maxn = 1000100;
int tab[maxn], n, m;

int main()
{
	ll n, k;
	cin >> n >> k;
	if (n > k) n = k;
	if (n + n <= k) OUT(0);
	ll MX = (k - 1) / 2, MI = max(1LL, k - n);
	//cout << MI << ' ' << MX << endl;
	if (MX < MI) OUT(0);
	cout << MX - MI + 1;
}