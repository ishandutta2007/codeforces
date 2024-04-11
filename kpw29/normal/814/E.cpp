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
#define maxn 152
int pref[maxn], t[maxn], jedynka[maxn], dwojka[maxn], n;
ll silnia[maxn], pot[maxn], invpot[maxn];
ll DP[51][51][maxn][51];
ll dp[51][51];

inline ll potmod(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1) res = (res * a)%mod;
		b /= 2;
		a = (a * a)%mod;
	}
	return res;
}

int getSum(int a, int b) {
	return pref[b] - pref[a-1];
}
int liczJedynki(int a, int b) {
	return jedynka[b] - jedynka[a-1];
}
int liczDwojki(int a, int b) {
	return dwojka[b] - dwojka[a-1];
}

int main()
{
	cin >> n;
	silnia[0] = 1;
	pot[0] = 1;
	invpot[0] = potmod(pot[0], mod - 2)%mod;
	
	FOR(i, 1, n)
	{
		silnia[i] = silnia[i-1] * i % mod;
		pot[i] = pot[i-1] * 2 % mod;
		invpot[i] = potmod(pot[i], mod - 2)%mod;
	}
	
	FOR(i, 1, n) {
		cin >> t[i];
		pref[i] = pref[i-1] + t[i];
		dwojka[i] = dwojka[i-1]; 
		jedynka[i] = jedynka[i-1];
		if (t[i] == 2) ++jedynka[i];
		else ++dwojka[i];
	}
	
	FOR(dwa, 0, n)
		FOR(jed, 0, n)
			FOR(remDwa, 0, dwa)
			FOR(edge, 0, 150)
			{
				if (edge == 0 && remDwa == 0) DP[jed][dwa][edge][remDwa] = 1;
				else if (edge == 0) DP[jed][dwa][edge][remDwa] = 0;
				else if (jed == 0)
				{
					if (dwa == 0)
					{
						if (edge == 0) DP[jed][dwa][edge][remDwa] = 1;
						else DP[jed][dwa][edge][remDwa] = 0;
					}
					else
					{
						DP[jed][dwa][edge][remDwa] = DP[jed][dwa - 1][edge][remDwa];
						if(dwa > 1 && remDwa > 1&&edge>1)DP[jed][dwa][edge][remDwa] += DP[jed + 1][dwa - 2][edge - 2][remDwa - 2] * (ll)(dwa - 1) % mod;
						if (dwa > 2 && remDwa > 2 && edge > 3)
						DP[jed][dwa][edge][remDwa] += DP[jed + 2][dwa - 3][edge - 4][remDwa - 3] * (ll)(((dwa - 1)*(dwa - 2))/2) % mod;
						DP[jed][dwa][edge][remDwa] %= mod;
					}
				}
				else
				{
					DP[jed][dwa][edge][remDwa] = DP[jed - 1][dwa][edge][remDwa];
					if (jed > 1&&edge>1) DP[jed][dwa][edge][remDwa] += DP[jed - 2][dwa][edge - 2][remDwa] * (ll)(jed - 1)%mod;
					if (dwa > 0&&edge>1) DP[jed][dwa][edge][remDwa] += DP[jed][dwa - 1][edge - 2][remDwa - 1] * (ll)dwa % mod;
					DP[jed][dwa][edge][remDwa] %= mod;
				}
				//if (DP[jed][dwa][edge][remDwa] > 0) cout << jed << ' ' << dwa << ' ' << edge << ' ' << remDwa << ' ' << DP[jed][dwa][edge][remDwa]<< endl;
			}
		
	dp[2][t[1] + 1] = 1;
	for (int i=2; i<n; ++i)
	{
		for (int j=2; j<=i; ++j)
		{
			if (dp[j][i] == 0) continue;
			//cout << j << ' ' << i << ' ' << dp[j][i] << endl;
			int remEdges = getSum(j, i) - (i - j + 1);
			for (int zostanie = 1; zostanie <= remEdges && i + zostanie <= n; ++zostanie)
			{
				int ld = liczDwojki(j, i);
				ll sposoby = 0;
				for (int remDwa = 0; remDwa <= ld; ++remDwa) {
					ll tmp = dp[j][i] * DP[liczJedynki(j, i)][ld][remEdges - zostanie][ld - remDwa] % mod;
					//cout << "Zostanie: " << zostanie << " wynik: " << DP[liczJedynki(j, i)][ld][remEdges - zostanie][ld - remDwa] << endl;
					//cout << tmp << endl;
					tmp *= silnia[zostanie] * invpot[remDwa] % mod;
					tmp %= mod;//cout << tmp << endl;
					sposoby += tmp;
					while (sposoby >=mod) sposoby -= mod;
				}
				dp[i + 1][i + zostanie] += sposoby;
				dp[i + 1][i + zostanie] %= mod;
			}
		}
	}
	
	ll result = 0;
	//teraz jeszcze tylko wynik dla n
	int i = n;
	for (int j=2; j<=n; ++j)
	{
		if (dp[j][i] == 0) continue;
		//cout << "Szansa: " << j << ' ' << i << ' ' << dp[j][i] << endl;
		int remEdges = getSum(j, i) - (i - j + 1);
		int ld = liczDwojki(j, i);
		//cout << "Zostalo: " << remEdges << ' ' << "Dwojek: " << ld << endl;
		ll sposoby = 0;
		for (int remDwa = 0; remDwa <= 0; ++remDwa) {
			ll tmp = dp[j][i] * DP[liczJedynki(j, i)][ld][remEdges][ld - remDwa] % mod;
			//cout << "Depek: " << DP[liczJedynki(j,i)][ld][remEdges][ld - remDwa] % mod << endl;
			tmp %= mod;
			sposoby += tmp;
			while (sposoby >= mod) sposoby -= mod;
		}
		result += sposoby;
		result %= mod;
		//cout << "Currres: " << result << endl;
	}
	
	cout << result;

}