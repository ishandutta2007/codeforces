#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

ll h[max_n];
vector<ll> b[max_n];
vector<ll> bi[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    ll n, k, l;
    cin >> n >> k >> l;

    ll m = n * k;
    for (int i = 0; i < n * k; ++i) {
        cin >> h[i];
    }
    sort(h, h + n * k);
    b[0].PB(h[0]);
    bi[0].PB(0);
    ll maxmh = h[0] + l;
    int last_ind;
    for (last_ind = 1; last_ind < m; ++last_ind) {
        if (h[last_ind] > maxmh) {
            break;
        }
    }
    last_ind--;
    if (last_ind + 1 < n) {
        cout << 0;
        return 0;
    }
    //cout << last_ind << endl;
    h[0] = -1;
    for (int i = n - 1; i > 0; --i) {
        b[i].PB(h[last_ind]);
        bi[i].PB(last_ind);
        h[last_ind] = -1;
        last_ind--;
    }
    int curh = 0;
    for (int curb = 0; curb < n; ++curb) {
        if (b[curb].size() == k) continue;
        while(h[curh] == -1) {
            ++curh;
        }
        if (h[curh] < b[curb][0]) {
            h[bi[curb][0]] = b[curb][0];
            b[curb][0] = h[curh];
            bi[curb][0] = curh;
            h[curh] = -1;
        }
        while(b[curb].size() < k) {
            while(h[curh] == -1) {
                ++curh;
            }
            b[curb].PB(h[curh]);
            bi[curb].PB(curh);
            h[curh] = -1;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll minn = b[i][0];
        for (int j = 1; j < k; ++j) {
            minn = min(minn, b[i][j]);
        }
        ans += minn;
    }
    cout << ans;
    return 0;
}