#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

ll m[max_n];
ll nxtn1[max_n];
ll sum[max_n];

int main()
{
   // freopen("input.txt", "r", stdin);
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
        sum[i] = m[i];
        if (i) {
            sum[i] += sum[i - 1];
        }
    }
    n++;
    m[n - 1] = 1e17;
    sum[n - 1] = sum[n - 2] + m[n - 1];
    m[n] = 10;
    for (int i = n - 1; i >= 0; --i) {
        if (m[i + 1] != 1) {
            nxtn1[i] = i + 1;
        } else {
            nxtn1[i] = nxtn1[i + 1];
        }
    }
    ll ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        //cout << i << endl;
        ll pr = 1;
        int cur = i;
        while(1) {
            pr *= m[cur];
            ll cursum = sum[cur];
            int nxt = nxtn1[cur];
            if (i) cursum -= sum[i - 1];

            if (1LL * k * cursum == pr) {
                ans++;
                //cout << i << endl;
                //cout << cur << endl;
            }

            if (pr - k * cursum > 0 && (pr - k * cursum) % k == 0) {
                ll cnt = (pr - k * cursum) / k;
                ll have = (nxt - cur - 1);
                if (have >= cnt) ans++;
            }


            ld nxtpr = (ld)1.0 * (ld)pr * (ld)m[nxt];
            ld maxpr = (ld)k * ((ld)cursum + (ld)200000);
            if (nxtpr > maxpr) {
                break;
            }
            //cout << nxtpr << endl;

            cur = nxt;
        }
    }
    cout << ans;
    return 0;
}