#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 400111, inf = 1000111222;

int m[max_n];
int sz, n;

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &sz);
    for (int i = 0; i < n; ++i) {
        scanf("%d", m + i);
    }
    sort(m, m + n);
    int k;
    for (k = 0; k < 25; ++k) {
        ll cntbit = k * n;
        ll cntbyte = (cntbit + 7) / 8;
        if (cntbyte > sz) {
            --k;
            break;
        }
    }
    ll cd = (1 << k);
    int r = 0;
    map<int, int> mp;
    ll ans = inf;
    for (int l = 0; l < n; ++l) {
        while (r < n) {
            if (mp.size() < cd) {
                mp[m[r]]++;
                ++r;
            } else if (mp.find(m[r]) != mp.end()) {
                mp[m[r]]++;
                ++r;
            } else {
                break;
            }
        }
        ans = min(ans, 1LL * l + (n - r));
        mp[m[l]]--;
        if (mp[m[l]] == 0) {
            mp.erase(mp.find(m[l]));
        }
    }
    cout << ans << endl;

    return 0;
}