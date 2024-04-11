#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const double EPS = 1e-9;
const int oo = 0x3f3f3f3;
const int MAXN = (int)1e5 + 10;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l, r, x;
    cin >> n >> l >> r >> x;

    vector<int> V(n);

    for (int i = 0; i < n; ++i)
        cin >> V[i];

    sort(V.begin(), V.end());

    int ans = 0;

    for (int i = 1; i < (1 << n); ++i){
        if ( (i & (i - 1)) == 0) continue;
        int tot = 0;
        int mn = V[n - 1], mx = V[0];
        for (int j = 0; j < n; ++j){
            if (i & (1 << j))
            {
                tot += V[j];
                mn = min(mn, V[j]);
                mx = max(mx, V[j]);
            }
        }
        if (l <= tot && tot <= r && mx - mn >= x)
            ++ans;
    }

    cout << ans << endl;

    return 0;
}