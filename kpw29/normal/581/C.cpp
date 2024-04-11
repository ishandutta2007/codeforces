#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18+3;

int n,m,a,b,c;
ll k;
int t[1000100];
vector <PII> ogar;

int F(int x)
{
	if (x == 0) return 10;
	else return x;
}
int main()
{
	ll wyn = 0;
	boost;
	cin >> n >> k;
	for (int i=1; i<=n; ++i) 
	{
		cin >> t[i];
		wyn += (t[i] / 10);
		ogar.pb(mp(F((100 - t[i]) % 10), 10 - (t[i] / 10)));
	}
	sort(ogar.begin(), ogar.end());
	
	for (int i=0; i<ogar.size(); ++i)
	{
		if (k >= ogar[i].e1 && ogar[i].e2 > 0)
		{
			++wyn;
			k -= ogar[i].e1;
			ogar[i].e2--;
		}
	}
	ll suma = 0;
	for (int i=0; i<ogar.size(); ++i) suma += ogar[i].e2;
	wyn += min(k / 10, suma);
	cout << wyn;
}