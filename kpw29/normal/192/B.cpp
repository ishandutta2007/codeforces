#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
#define boost ios_base::sync_with_stdio(false)
#define milion 1000100
#define tysiac 1010
#define dwa_tysiace 2010
#define sto_tysiecy 100100
typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned int ui;
typedef pair <int, int> BONG;
typedef pair <BONG, BONG> LONG;
const int inf = 1e9+9;
const int mod = 1e9+7;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b;

int t[tysiac];
int main()
{
	int n;
	scanf("%d", &n);
	int days = inf;
	for (int i=1; i<=n; ++i) scanf("%d", &t[i]);
	for (int i=1; i<n; ++i) days = min(days, max(t[i], t[i+1]));
	days = min(days, t[1]);
	days = min(days, t[n]);
	printf("%d", days);
	return 0;
}