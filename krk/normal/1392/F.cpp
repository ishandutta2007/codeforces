#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

int n;
ll H[Maxn];
ll sum;
ll a[Maxn];
vector <int> seq;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &H[i]);
        sum += H[i];
    }
    for (int i = 0; i + 1 < n; i++)
        a[i] = H[i + 1] - H[i];
    if (1 < n) {
        a[1] += a[0] / 2;
        a[0] %= 2;
        if (a[0] == 0) seq.push_back(0);
        for (int i = 1; i + 1 < n; i++) {
            // end
            while (!seq.empty() && a[i] > 1) {
                ll tk = min(ll(i - 1 - seq.back()), a[i] - 1);
                seq.back() += tk;
                a[i] -= tk;
                a[i + 1] += tk;
                if (seq.back() == i - 1) {
                    if (a[i] > 1) {
                        a[i] -= 2;
                        seq.pop_back();
                        a[i + 1]++;
                    }
                }
            }
            // full beg
            ll tims = a[i] / (i + 2);
            a[i] -= tims * (i + 2);
            a[i + 1] += tims * (i + 1);
            // part beg
            if (a[i] > 1) {
                int by = a[i] - 1;
                a[i] -= by;
                a[i + 1] += by;
                seq.push_back(-1 + by);
            }
            if (a[i] == 0)
                seq.push_back(i);
        }
    }
    fill(a, a + n, 1ll);
    for (int i = 0; i < seq.size(); i++)
        a[seq[i]] = 0;
    ll cur = 0, tot = 0;
    for (int i = 0; i + 1 < n; i++) {
        cur += a[i];
        tot += cur;
    }
    sum -= tot;
    H[0] = sum / n;
    for (int i = 1; i < n; i++)
        H[i] = H[i - 1] + a[i - 1];
    for (int i = 0; i < n; i++)
        printf("%I64d%c", H[i], i + 1 < n? ' ': '\n');
    return 0;
}