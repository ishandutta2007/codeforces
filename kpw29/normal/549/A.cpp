#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define root 1
#define maxn 300100
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> BONG;
typedef pair <ll, ll> LONG;
typedef pair <BONG, BONG> DONG;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b,c;
ll N,M,P,Q,A,B,C;

char s[60][60];
int main()
{
	scanf("%d%d", &n, &m);
	vector <char> w;
	char zn;
	zn = 'f';
	w.pb(zn);
	zn = 'a';
	w.pb(zn);
	zn = 'c';
	w.pb(zn);
	zn = 'e';
	w.pb(zn);
	sort(w.begin(), w.end());
	int wyn = 0;
	for (int i=1; i<=n; ++i) scanf("%s", s[i]+1);
	for (int i=1; i<n; ++i)
	for (int j=1; j<m; ++j)
	{
		vector <char> zb;
		zb.clear();
		zb.pb(s[i][j]);
		zb.pb(s[i+1][j]);
		zb.pb(s[i][j+1]);
		zb.pb(s[i+1][j+1]);
		sort(zb.begin(), zb.end());
		if (zb == w) ++wyn;
	}
	printf("%d", wyn);
	return 0;
}