#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
typedef vector <int> vi;
const ll mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
int n, m,k, a, b, c;
#define maxn 2000100
int  tab[maxn];
string s;
char slowo[maxn];

int f[maxn];
inline int find(int x)
{
	if (f[x] == x) return x;
	f[x] = find(f[x]);
	return f[x];
}

int LEN;

int main()
{
	boost;
	FOR(i, 0, maxn - 2) f[i] = i;
	FOR(i, 0, maxn - 2) slowo[i] = 'a';
	cin >> n;
	int MAX = 0;
	FOR(i, 1, n)
	{
		cin >> s;
		int len = s.length(), ile;
		cin >> ile;
		FOR(step,1,ile)
		{
			cin >> a;
			MAX = max(MAX, a + len - 1);
			int pos = find(a);
			while (pos <= a + len - 1)
			{
				//cout << "Ustawiam: " << pos << ' ' << pos - a << endl;
				slowo[pos] = s[pos - a];
				f[pos] = find(pos + 1);
				pos = f[pos];
			}
		}
	}
	
	FOR(i, 1, MAX) cout << slowo[i];
}