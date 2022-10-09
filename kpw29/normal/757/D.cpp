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
#define maxn 80

const int M = (1 << 20);
int dp[76][M + 5], n;

string s;
int tab[maxn];

int main()
{
	boost;
	cin >> n;
	cin >> s;
	FOR(i, 0, n-1) tab[i + 1] = s[i] - '0';
	
	dp[0][0] = 1;
	ll wyn = 0;
	FOR(i, 1, n)
	{	
		ll val = 0;
		int gdzieJaJestem = i;
		dp[gdzieJaJestem][0] = 1;
		
		for (int kk=1; kk<=i; ++kk)
		{
			if (kk > 5 && tab[i-kk+1] == 1) break;
			val += tab[i-kk+1] * (1 << (kk-1));
			//cout << val << endl;
			if (val > 0 && val <= 20)
			{
				int w = val - 1;
				int gdzieJaBede = gdzieJaJestem - kk;

				FOR(j, 0, M-1) 
				{
					dp[gdzieJaJestem][j | (1 << w)] += dp[gdzieJaBede][j];
					while (dp[gdzieJaJestem][j | (1 << w)] >= mod) dp[gdzieJaJestem][j | (1 << w)] -= mod;
				}
			}
		}
		//cout << endl;
		
		FOR(j, 1, 20) wyn += dp[gdzieJaJestem][(1 << j) - 1];
		
	}
	
	wyn %= mod;
	cout << wyn;
}