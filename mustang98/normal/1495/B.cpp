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

int m[max_n];
int decl[max_n];
int decr[max_n];
int incl[max_n];
int incr[max_n];
int pr[max_n];
int sf[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    decl[0] = incl[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (m[i] > m[i - 1]) {
            decl[i] = decl[i - 1] + 1;
            incl[i] = 1;
        } else {
            incl[i] = incl[i - 1] + 1;
            decl[i] = 1;
        }
    }
    decr[n - 1] = incr[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        if (m[i] > m[i + 1]) {
            decr[i] = decr[i + 1] + 1;
            incr[i] = 1;
        } else {
            incr[i] = incr[i + 1] + 1;
            decr[i] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        pr[i] = max(incl[i], incr[i]);
        if (i) {
            pr[i] = max(pr[i], pr[i - 1]);
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        sf[i] = max(incl[i], incr[i]);
        if (i + 1 < n) {
            sf[i] = max(sf[i], sf[i + 1]);
        }
    }


    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = decl[i], r = decr[i];
        int mx = max(l, r);
        bool dwin;
        int ll = i - l, rr = i + r;
        int m2 = max(incl[ll + 1], incr[rr - 1]);
        if (ll > 0) m2 = max(m2, pr[ll]);
        if (rr < n) m2 = max(m2, sf[rr]);

        if (l == r) {
            if (r % 2 == 0) {
                dwin = true;
            } else {
                dwin = false;
                if (m2 >= r) {
                    dwin = true;
                }
            }
        } else {
            dwin = true;
        }
        ans += (dwin == false);
    }
    cout << ans << endl;
    return 0;
}