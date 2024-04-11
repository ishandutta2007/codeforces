#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int inf = 1000 * 1000 * 1000;
long long ans[80][2010];
long long me[2010];
int n;

int main ()
{
    vector <pair <int, pii > > e;

    scanf("%d", &n);

    for (int i = 0; i < n; i ++)
    	me[i] = inf;

    for (int i = 0; i < n; i ++)
    	for (int j = i + 1; j < n; j ++)
    	{
            int d;
    		scanf("%d", &d);
    		me[i] = min(me[i], d + 0ll);
    		me[j] = min(me[j], d + 0ll);
    		e.pb(mp(d, mp(i, j)));
    	}

    sort(e.begin(), e.end());

    for (int j = min(n, 80) - 1; j >= 0; j --)
    {
    	for (int i = 0; i < n; i ++)
    		ans[j][i] = me[i] * 1ll * (n - 1 - j);
    	if (j < min(n, 80) - 1)
    	{
		    for (int i = 0; i < (int) e.size(); i ++)
		    {
    			int u = e[i].sc.fs;
    			int v = e[i].sc.sc;
    			long long val = e[i].fs;

    			ans[j][u] = min(ans[j][u], ans[j + 1][v] + val);
    			ans[j][v] = min(ans[j][v], ans[j + 1][u] + val);
    		}
    	}
    	if (j < min(n, 80) - 2)
    	{
    		long long best = inf * 1ll * n;
    		for (int i = 0; i < n; i++)
    			best = min(best, ans[j + 2][i]);
    		for (int i = 0; i < n; i++)
    			ans[j][i] = min(ans[j][i], best + me[i] * 2ll);
    	}
    }

    for (int i = 0; i < n; i ++)
    	cout << ans[0][i] << endl;

    return 0;
}