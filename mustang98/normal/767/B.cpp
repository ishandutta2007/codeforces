#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111;
const ll inf = 1000000000LL * 1000000000LL;

ll tin[max_n];
ll fin[max_n];
ll eq[max_n];


int main()
{
    ll ts, tf, t;
    int n, ns;
    cin >> ts >> tf >> t;
    cin >> n;
    ns = n;
    ll curt = ts;
    for (int i = 0; i < n; ++i)
    {
        cin >> tin[i];
        fin[i] = -1;
    }

    for (int i = 0; i < n; ++i)
    {
        if (curt > tf)
        {
            n = i;
            break;
        }
        fin[i] = max(tin[i], curt) + t - 1;
        curt = fin[i] + 1;
    }

    /*for (int i = 0; i < n; ++i)
    {
        cout << fin[i] << ' ';
    }
    cout << endl;
*/
    ll mint = inf, start;
    for (int i = n - 1; i >= 0; --i)
    {
        if (tin[i] == 0) continue;
        if (i && tin[i - 1] == tin[i]) continue;
        ll igo = tin[i] - 1;
        ll ist;
        if (i) ist = max(igo, fin[i - 1] + 1);
        else ist = max(igo, ts);
        ll ifin = ist + t - 1;
        if (ifin >= tf) continue;
        ll time = ist - igo;
        if (time < mint)
        {
            mint = time;
            start = igo;
        }
    }

    ll lastt = tf - t;
    int prev = -1;
    for (int i = ns - 1; i >= 0; --i)
    {
        if (tin[i] <= lastt)
        {
            prev = i;
            break;
        }
    }
    ll mint1;
    if (prev == -1)
    {
        cout << lastt;
        return 0;
    }
    else if (fin[prev] != -1 && fin[prev] < lastt)
    {
        cout << lastt;
        return 0;
    }

    if (mint == inf)
    {
        exit(228);
    }
    cout << start;
    return 0;
}