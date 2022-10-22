#include <iostream>
#include <iomanip>
using namespace std;

typedef long double ld;

const int Maxn = 10000;
const ld sm = 0.000000001;

int n, k;
ld a[Maxn], ans;

bool Enough(ld eq)
{
     ld giv = 0, get = 0;
     for (int i = 0; i < n; i++)
        if (a[i] > eq) giv += a[i] - eq;
        else if (a[i] < eq) get += eq - a[i];
     return giv - giv * ld(k) / ld(100) >= get;
}

void Search(ld l, ld r)
{
     if (l + sm > r) return;
     ld mid = (l + r) / 2;
     if (Enough(mid)) {
                      ans = mid;
                      Search(mid + sm, r);
     } else Search(l, mid - sm);
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    Search(0, 1000);
    cout << fixed << setprecision(9) << ans << endl;
    return 0;
}