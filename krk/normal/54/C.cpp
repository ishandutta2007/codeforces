#include <iostream>
#include <iomanip>
using namespace std;

typedef long double ld;
typedef long long ll;

const int Maxn = 1001;

ld prob[Maxn], ans;

void Calc(ll l, ll r, ll &s1, ll &ns1)
{
     ll n = r-l+1, d = 1;
     s1 = 0;
     while (l/10 >= d) d *= 10;
     if (l / d != 1) { d *= 10; l = d; }
     while (l <= r) {
           if (2*d <= r) {
                   s1 += d - (l - d);
                   d *= 10; l = d;
           } else {
                  s1 += r-l+1;
                  break;
           }
     }
     ns1 = n - s1;
}

int main()
{
    int n, k;
    ll l, r, s1, ns1;
    cin >> n;
    prob[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> l >> r;
        Calc(l, r, s1, ns1);
        for (int j = i; j >= 0; j--)
           if (j) prob[j] = prob[j-1] * ld(s1) / ld(s1 + ns1) + prob[j] * ld(ns1) / ld(s1 + ns1);
           else prob[j] = prob[j] * ld(ns1) / ld(s1 + ns1);
    }
    cin >> k;
    for (int i = 0; i <= n; i++)
       if (100*i >= n*k) ans += prob[i];
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}