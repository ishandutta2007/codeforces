#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const int N = 1e5 + 5;
const double eps = 1e-7;
const long long M = 1e9 + 7;

int n, a[N], kol[N], is[N][31], val[N], only[N];

signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int pos = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int b = 0; b < 31; b++)
            if ((a[i] >> b) & 1) {
                kol[i]++;
                is[i][b] = 1;
                if (only[b] == 1)
                    only[b] = 2;
                if (only[b] == 0)
                    only[b]++;
            }
    }
    for (int i = 0; i < n; i++) {
        for (int b = 0; b < 31; b++)
            if (((a[i] >> b) & 1) && only[b] == 1)
                val[i] += (1 << b);
        if (val[i] > val[pos])
            pos = i;
    }
    cout << a[pos] << ' ';
    for (int i = 0; i < n; i++)
        if (i != pos)
            cout << a[i] << ' ';
    return 0;
}