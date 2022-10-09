#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
typedef long long int ll;
typedef pair <int, int> BONG;
typedef unsigned int ui;
const ll inf = 1e18;
int n, k;
#define maxn 1010
ll wyn =inf;
int t[maxn];
int main()
{
	cin >> n;
	for (int i=1; i<=n; ++i) cin >> t[i];
	for (int i=1; i<=n; ++i)
	{
		ll tmp_wyn = 0;
		ll a;
		for (int j=1; j<=t[i]; ++j)
		{
			cin >> a;			
			tmp_wyn += 5*a;
		}
		tmp_wyn += 15 * t[i];
		wyn = min(wyn, tmp_wyn);
	}
	cout << wyn;
}