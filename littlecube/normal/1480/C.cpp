#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

signed main()
{

    fast;
    int n, L = 1, R;
    cin >> n;
    R = n;
    while (R - L > 1)
    {
        int Lmid = (L + R) / 2, Rmid = (L + R) / 2 + 1, Lmidval, Rmidval;
        cout << "? " << Lmid << endl;
        cin >> Lmidval;
        cout << "? " << Rmid << endl;
        cin >> Rmidval;
        if (Lmidval > Rmidval)
            L = Rmid;
        else
            R = Lmid;
    }
    if (R - L == 1)
    {
        int Lval, Rval;
        cout << "? " << L << endl;
        cin >> Lval;
        cout << "? " << R << endl;
        cin >> Rval;
        if (Lval > Rval)
            cout << "! " << R << endl;
        else
            cout << "! " << L << endl;
    }
    else
        cout << "! " << L << endl;
}