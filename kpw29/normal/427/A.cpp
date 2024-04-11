#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define mp make_pair
#define pb push_back
#define milion 1000100
#define tysiac 1010
#define boost ios_base::sync_with_stdio(false)
typedef long long ll;
typedef pair <int, int> BONG;
typedef pair <BONG, BONG> DONG;
typedef pair <ll, ll> LONG;
typedef unsigned int ui;
typedef unsigned long long ull;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18+3;

int n,m,a,b,c;

int main()
{
	int akt = 0;
	int wyn =0;
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
	{
		scanf("%d", &a);
		akt += a;
		if (akt < 0) ++wyn;
		akt = max(akt, 0);
	}
	printf("%d ", wyn);
}