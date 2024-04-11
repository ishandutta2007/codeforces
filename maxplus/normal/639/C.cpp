#include <iostream>

using namespace std;

const int N = 200003;
int64_t n, k, a[N], cr[N], cv[N], ans;
bool fr[N], fv[N];

int main()
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    cin >> n >> k; ++n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int64_t i = 0, cr = 0; i < n; ++i)
    {
        if (cr & 1)
        {
            while (i < n)
                fr[i++] = 1;
            break;
        }
        cr /= 2;
        ::cr[i] = cr;
        cr += a[i];
    }
    for (int64_t i = n - 1, cv = 0; i > -1; --i)
    {
        cv *= 2;
        if (cv >= 2 * k || cv <= -2 * k)
        {
            while (i > -1)
                fv[i--] = 1;
            break;
        }
        ::cv[i] = cv;
        cv += a[i];
    }
    for (int i = 0; i < n; ++i) if (!fv[i] && !fr[i])
        ans += cv[i] + cr[i] <= k && cv[i] + cr[i] >= -k && (i != n - 1 || cv[i] + cr[i]);
    cout << ans;
    return 0;
}