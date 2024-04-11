#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

ll gcd(ll a, ll b) {
    return b == 0LL ? a : gcd(b, a % b);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    vector<bool> res;
    int T;
    cin >> T;
    while (T--) {
        ll p, q, b;
        scanf("%I64d %I64d %I64d", &p, &q, &b);
        //cin >> p >> q >> b;
        ll gc = gcd(p, q);
        p /= gc;
        q /= gc;
        bool isbr = 0;
        while (q > 1) {
            gc = gcd(q, b);
            if (gc == 1) {
                res.PB(0);
                isbr = 1;
                break;
            }
            while (q % gc == 0) {
                q /= gc;
            }
            b = gc;
        }
        if (!isbr) {
            res.PB(1);
        }
    }
    for (int i = 0; i < res.size(); ++i) {
        if (res[i]) {
            printf("Finite\n");
        } else {
            printf("Infinite\n");
        }
    }
    return 0;
}