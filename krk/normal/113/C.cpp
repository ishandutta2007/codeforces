#include <iostream>
#include <algorithm>
using namespace std;

const int Maxb = 17330;

int l, r;
bool comp[Maxb];
int pr[Maxb], prl;
bool prime[Maxb];
int res;

int main()
{
    cin >> l >> r;
    if (l <= 2 && 2 <= r) res++;
    if (l <= 2) l = 3;
    for (int i = 3; i * i <= r; i += 2) if (!comp[i]) {
        pr[prl++] = i;
        for (int j = i * i; j <= r / j; j += 2 * i) comp[j] = true;
    }
    for (int i = 0; i <= r / Maxb; i++) {
        fill(prime, prime + Maxb, true);
        int beg = i * Maxb;
        for (int j = 0; j < prl; j++)
            for (int l = max((beg + pr[j] - 1) / pr[j], 2) * pr[j] - beg; l < Maxb; l += pr[j])
                prime[l] = false;
        int val = beg;
        for (int j = 0; j < Maxb && val <= r; j++, val++)
            if (l <= val && prime[j] && (val & 3) == 1) res++;
    }
    cout << res << endl;
    return 0;
}