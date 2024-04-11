#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 500111, inf = 1000111222;

ll m[max_n];
ll ps[max_n];
ll ss[max_n];
ll pm[max_n];
ll sm[max_n];

ll aps[max_n];
ll ass[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", m + i);
    }
    ps[0] = m[0];
    pm[0] = m[0];
    aps[0] = abs(m[0]);
    for (int i = 1; i < n; ++i) {
        ps[i] = ps[i - 1] + m[i];
        pm[i] = min(pm[i - 1], m[i]);
        aps[i] = aps[i - 1] + abs(m[i]);
    }


    ss[n - 1] = m[n - 1];
    sm[n - 1] = m[n - 1];
    ass[n - 1] = abs(m[n - 1]);
    for (int i = n - 2; i >= 0; --i) {
        ss[i] = ss[i + 1] + m[i];
        sm[i] = min(sm[i + 1], m[i]);
        ass[i] = ass[i + 1] + abs(m[i]);
    }

    ll best = -1e18;
    for (int mid = 0; mid < n; ++mid) {
        ll ansl = 0, ansr = 0;
        if (mid > 0) {
            if (pm[mid - 1] >= 0) {
                ansl = ps[mid - 1] - 2 * pm[mid - 1];
            } else {
                ansl = aps[mid - 1];
            }
        }
        if (mid + 1 < n) {
            if (sm[mid + 1] >= 0) {
                ansr = ss[mid + 1] - 2 * sm[mid + 1];
            } else {
                ansr = ass[mid + 1];
            }
        }
        ll ans = m[mid] + ansl + ansr;
        best = max(best, ans);
    }
    cout << best;

    return 0;
}