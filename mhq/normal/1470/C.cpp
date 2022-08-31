#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
int PT = 1e4;
const int maxN = 1e5 + 10;
ll F[maxN];
ll ask(int x) {
#ifdef DEBUG
    int dist = (x >= PT ? x - PT + 1 : (n - (PT - x) + 1));
    assert(1 <= dist && dist <= n);
    return F[dist];
#else
    cout << "? " << x << endl;
#endif
    ll resp;
    cin >> resp;
    return resp;
}
int cand[maxN];
int SZ = 0;
ll NF[maxN];
int val(int x, int PT) {
    int dist = (x >= PT ? x - PT + 1 : (n - (PT - x) + 1));
    return dist;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> k;
//    n = 1e5;
//    k = 1e9;
    for (int i = 1; i <= n; i++) {
        F[i] = k;
    }
    int step = 750;
    while (__gcd(step, n) != 1) step++;
    for (int i = 0; i < n; i++) cand[i] = i + 1;
    SZ = n;
    int cur = 1;
    int cc  = 0;
    while (SZ > 1) {
        assert(cc <= 1000);
        ++cc;
        cur = (cur + step - 1) % n + 1;
        if (SZ <= 200) {
            int any = -1;
            for (int i = 1; i < SZ; i++) {
                if (any != -1) break;
                for (int j = 1; j <= n; j++) {
                    if (F[val(j, cand[0])] != F[val(j, cand[i])]) {
                        any = j;
                        break;
                    }
                }
            }
            if (any != -1) cur = any;
        }
//        cout << cur << " hi " << endl;
        ll what = ask(cur);
        int NSZ = 0;
        for (int i = 0; i < SZ; i++) {
            int dst = (cur >= cand[i] ? cur - cand[i] + 1 : (n - (cand[i] - cur) + 1));
            if (what == F[dst]) {
                cand[NSZ] = cand[i];
                NSZ++;
            }
        }
        SZ = NSZ;
        for (int i = 1; i <= n; i++) {
            NF[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int prv = i - 1;
            if (prv == 0) prv = n;
            int nxt = i + 1;
            if (nxt == n + 1) nxt = 1;
            if (i != 1) {
                NF[prv] += F[i] / 2;
                NF[nxt] += (F[i] + 1) / 2;
            }
            else {
                NF[nxt] += F[i];
            }
        }
        int pppp = 0;
        for (int i = 1; i <= n; i++) {
            F[i] = NF[i];
            NF[i] = 0;
            if (F[i] != k) pppp++;
        }
    }
    cout << "! " << cand[0] << endl;
    return 0;
}