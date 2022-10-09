#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
typedef vector<int> vi;
typedef bitset<101> bset;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 100100
int n, m, a, b, c;

int zlicz[maxn];

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) {
		cin >> a;
		zlicz[a]++;
	}

	int wyn = 1;
	
	FOR(i, 2, maxn-100) {
		int ww = 0;
		for (int j=i; j<maxn; j+=i) ww += zlicz[j];
		wyn = max(wyn, ww);
	}
	cout << wyn;
}