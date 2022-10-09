#include <bits/stdc++.h>
#include <string>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1003

int n, m, a, b, c, d, T, st;
set <ll> poczatki, konce;

int main()
{
	poczatki.insert(0); konce.insert(0);
	poczatki.insert(INF);
	konce.insert(INF);
	boost;
	cin >> n;
	FOR(i, 1, n) {
		cin >> st >> d;
		ll koniec = st + d - 1;
		set <ll>::iterator it, aa = poczatki.begin();
		bool ok = 1;
		for (it=konce.begin(); it != konce.end(); ++it) {
			if (aa == konce.end()) break;
			int kon = (*it), pocz = *aa;
			bool ANS = (kon < st || koniec < pocz);
			ok &= ANS;
			++aa;
		}
		//cout << kk << ' ' << ff << endl;
		if (ok)
		{
			poczatki.insert(st);
			konce.insert(koniec);
			cout << st << ' ' << koniec << "\n";
		}
		else
		{
			set <ll>::iterator it, aa = poczatki.begin();
			for (it=konce.begin(); it != konce.end(); ++it) {
				++aa;
				int pocz = (*it) + 1;
				if (pocz + d - 1 < (*aa)) {
					poczatki.insert(pocz);
					konce.insert(pocz + d - 1);
					cout << pocz << ' ' << pocz + d - 1 << "\n";
					break;
				}
			}
		}
	}
}