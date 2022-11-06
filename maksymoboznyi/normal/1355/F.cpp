#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 630;

int good[N];

int kol(int x) {
    int res = 1;
    int p = 2;
    int X = x;
    while (1) {
        while (p * p <= X && x % p != 0)
            p++;
        if (p * p > X)
            break;
        int t = 0;
        while (x % p == 0)
            t++, x /= p;
        res *= (t + 1);
    }
    if (x != 1)
        res *= 2;
    return res;
}

bool was[N];

signed main()
{
    int t;
    vector<int> p;
    for (int i = 2; i < N; i++)
        if (!good[i]) {
            p.pb(i);
            for (int j = i; j * i < N; j++)
                good[j * i] = 1;
        }
    cin >> t;
    while (t--) {
        int ANS = 4194304;
        vector<int> h;
        int cur = 0;
        while (cur < p.size()) {
            int q = 1;
            int bcur = cur;
            while (cur < p.size() && q <= 1000000000'000000000ll / p[cur])
                q *= p[cur], cur++;
            cout << "? " << q << endl;
            int v = __gcd(q, ANS);
            cin >> v;
            for (int i = bcur; i < cur; i++)
                if (v % p[i] == 0)
                    h.pb(p[i]);
        }
        int res = 1;
        for (int i = 0; i < h.size(); i += 2) {
            int q1 = 1, q2 = 1;
            while (q1 * h[i] <= 1e9)
                q1 *= h[i];
            if (i + 1 != h.size())
                while (q2 * h[i + 1] <= 1e9)
                    q2 *= h[i + 1];
            cout << "? " <<q1 * q2 << endl;
            int v = __gcd(q1 * q2, ANS);
            cin >> v;
            int k1 = 0, k2 = 0;
            while (v % h[i] == 0)
                v /= h[i], k1++;
            if (i + 1 != h.size())
                while (v % h[i + 1] == 0)
                    v /= h[i + 1], k2++;
            res *= (k1 + 1) * (k2 + 1);
        }
        cout << "! " << max(res + 7, res * 2) << endl;
    }
    return 0;
}