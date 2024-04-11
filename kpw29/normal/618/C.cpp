#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define root 1
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <ll, ll> PLL;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b,d,k;
ll N,M,P,Q,A,C;
#define maxn 1000100
int tab[1010][1010];

PLL area;
PLL t[maxn];
ll det(ll a, ll b, ll c, ll d) {
	return a * d - b * c;
}
long long pole(int a, int b, int c)
{
	return abs(det(t[a].e1, t[a].e2, t[b].e1, t[b].e2) + det(t[b].e1, t[b].e2, t[c].e1, t[c].e2) + det(t[c].e1, t[c].e2, t[a].e1, t[a].e2));
}
ll sqr(ll x) {
	return x * x;
}
ll distance(int a, int b) {
	return sqr(t[a].e1 - t[b].e1) + sqr(t[a].e2 - t[b].e2);
}
int main()
{
	boost;
	cin >> n;
	area = mp(INF + INF + INF + INF + INF + INF + INF, 0);
	for (int i=1; i<=n; ++i) cin >> t[i].e1 >> t[i].e2;
	PLL klucz = mp(INF + INF + INF + INF + INF + INF, 0);
	
	for (int i=2; i<=n; ++i)
	{
		ll od = distance(1, i);
		if (od < klucz.e1) klucz = mp(od, i);
	}
	
	for (int i=2; i<=n; ++i)
	{
		if (i == klucz.e2) continue;
		ll f = pole(1, klucz.e2, i);
		if (!f) continue;
		if (f < area.e1) area = mp(f, i);
	}
	cout << 1 << ' ' << klucz.e2 << ' ' << area.e2;
}