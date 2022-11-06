#include <bits/stdc++.h>
#define pb push_back
#define ll double

using namespace std;
const int N = 2000;
set<ll> s;
ll n,  y[N];
struct cell
{
    ll x, y;
};
vector<cell> p;
bool is[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> y[i];
        p.pb({i, y[i]});
    }
    int i = 1;
    ll a1, b1, c1, a2, b2, c2, a3, b3;
    for (int j = 2; j <= n; j++)
    {
        a2 = y[i] - y[j];
        b2 = j-i;
        c2 = i*y[j]-j*y[i];
        for (int k = 0; k <= n; k++)
            is[k] = 0;
        for (int k = 1; k <= n; k++)
            if (a2*k+b2*y[k]+c2 == 0)
                is[k] = 1;
        int p1 = -1, p2 = -1;
        for (int k = 1; k <= n; k++)
            if (!is[k])
                if (p1 == -1)
                    p1 = k;
                else
                    p2 = k;
        if (p1 == -1)
            continue;
        a1 = y[p1] - y[p2];
        b1 = p2-p1;
        c1 = p1*y[p2]-p2*y[p1];

        for (int k = 1; k <= n; k++)
            if (a1*k+b1*y[k]+c1 == 0)
                is[k] = 1;
        bool r = false;
        for (int k = 1; k <=  n; k++)
            if (!is[k])
        {
            r = true;
            break;
        }
        if (a2 != 0)
            a3 = a1/a2;
        else
            a3 = -1000000001;
        if (b2 != 0)
            b3 = b1/b2;
        else
            b3 = -1000000001;
        if (a1 == 0 && a2 == 0)
            a3 = b3;
        if (b1 == b2 && b2 == 0)
            b3 = a3;
        if (p2 == -1)
        {
            cout <<"Yes";
            return 0;
        }
        if (!r && a3 == b3)
        {
        //    cout << a1 << ' ' << b1 << ' '<< a2 << ' '<<b2 << endl;
            cout << "Yes";
            return 0;
        }
    }
    ll a, b ,c;
    a = y[2] - y[3];
    b = 1;
    c = 2*y[3] - 3*y[2];
    for (int i = 1; i <= n; i++)
        is[i] = 0;
    for (int i = 1; i <= n; i++)
        if (i*a+b*y[i]+c==0)
            is[i] = 1;
    int kol = 0;
    for (int i = 1; i <= n; i++)
        if (!is[i])
        kol++;
    if (!is[1] && kol == 1)
        cout << "Yes";
    else
    cout << "No";
    return 0;
}