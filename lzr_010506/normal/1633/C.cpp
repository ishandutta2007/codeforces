#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, x) for(int i = 0; i < x; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define X first
#define Y second
#define pii pair<int, int>
#define ll long long
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T --)
	{
		ll hc, dc, hm, dm, k, w, a;
		cin >> hc >> dc >> hm >> dm >> k >> w >> a;
	    hc += k * a;
	    rep0(i, k + 1)
	    {
	        if(ceil(hc * 1.0 / dm) >= ceil(hm * 1.0 / dc)) {cout << "YES\n"; goto L1;}
	        hc -= a;
	        dc += w;
	    }
	    cout << "NO\n";
	    L1:;
	}
}