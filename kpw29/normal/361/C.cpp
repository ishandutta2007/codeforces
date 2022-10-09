#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false);}
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 5010
ll tab[maxn], stab[maxn], place;
int n ,k;
PP zap[maxn];
const ll ifff = 1e9;
int main()
{
	boost;
	cin >> n >> k;
	FOR(i, 1, k) cin >> zap[i].e1.e1 >> zap[i].e1.e2 >> zap[i].e2.e1 >> zap[i].e2.e2;
	FOR(i, 1, n) tab[i] = INF;
	for (int i=k; i>0; --i)
	{
		int que = zap[i].e1.e1;
		if (que == 1)
		{
			FOR(j, zap[i].e1.e2, zap[i].e2.e1) tab[j] -= zap[i].e2.e2;
		}
		else
		{
			FOR(j, zap[i].e1.e2, zap[i].e2.e1) tab[j] = min(tab[j], zap[i].e2.e2);
		}
	}
	
	FOR(i, 1, n) tab[i] = min(tab[i], (ll)1e9), stab[i] = tab[i];
	
	FOR(i, 1, n)
	  if (abs(tab[i]) > ifff) OUT("NO");

	FOR(i, 1, k)
	{
		int que = zap[i].e1.e1;
		//FOR(j, 1, n) cout << stab[j] << ' ';
		//cout << endl;
		if (que == 1) FOR(j, zap[i].e1.e2, zap[i].e2.e1) stab[j] += zap[i].e2.e2;
		else
		{
			ll MAXX = -INF;
			FOR(j, zap[i].e1.e2, zap[i].e2.e1) MAXX = max(MAXX, stab[j]);
			if (MAXX != zap[i].e2.e2) 
			{
				//cout << i;
				OUT("NO");
			}
		}
	}
	
	cout << "YES\n";
	FOR(i, 1, n) cout << tab[i] << ' ';
	
}