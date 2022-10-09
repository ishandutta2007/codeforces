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
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;

int n,m,a,b,c;
ll N,M,A,B,C;
char s[3010][3010];
#define maxn 1000100
int zap[maxn];
int  pole, statki, dl;
set <int> pozycje;
int fun(int a)
{
	return (a + 1) / (dl + 1);
}
int main()
{
	boost;
	cin >> pole >> statki >> dl;
	cin >> n;
	pozycje.insert(0); pozycje.insert(pole + 1);
	for (int i=1; i<=n; ++i) cin >> zap[i];
	int ile = fun(pole);
	for (int i=1; i<=n; ++i)
	{
		int poz = zap[i];
		set <int> ::iterator it = pozycje.upper_bound(poz);
		int prawo = *it;
		--it; int lewo = *it;
		pozycje.insert(poz);
		int dlugosc = prawo - lewo - 1;
		ile -= fun(dlugosc);
		ile += fun(poz - lewo - 1) + fun(prawo - poz - 1);
		//cout << ile << endl;
		if (ile < statki) OUT(i);
	}
	puts("-1");
	
}