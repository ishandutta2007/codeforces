#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod(ll a, ll m)
{
    a %= m;
    return a < 0 ? a + m : a;
}

ll getyear(ll y, int len)
{
    ll year = 1989, powten = 1;
    for (ll strip = y, llen = len; /* (strip > 0 && llen < 0) || */ llen > 0; strip /= 10, powten *= 10, llen--) {
        ll digit = strip % 10;
        ll cdigit = (year / powten) % 10;
        if (digit != cdigit) {
            year += powten * mod(digit - cdigit, 10);
        }
//        cerr << cdigit << " -> " << digit << ": " << year << endl;
    }

    ll lenCap = powten;

//    ll lenCap = 1;
//    for (int llen = len; llen-- > 0; lenCap *= 10);
//    cerr << len << ": " << lenCap << endl;
//    assert(bigpowten == lenCap);

    if (len != 1) {
        ll suby = mod(y, lenCap / 10);
        ll sub = getyear(suby, len - 1);
//        cerr << "Sub: " << sub << endl;
        if (sub >= year) {
            year += lenCap;
        }
    }

//    ll ytmp = y;
//    for (powten /= 10; powten >= 1; powten /= 10) {
//        if ((ytmp / powten) * powten == 0) {
//            continue;
//        }
//
//        ytmp = ytmp - (ytmp / powten) * powten;
//        if (getyear(ytmp, -1) == year) {
//            year += bigpowten;
//            powten = bigpowten;
//        }
//    }
    return year;
}

int main()
{
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
#else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif // LOCAL

    int n;
    cin >> n;
    string s;
    getline(cin, s);
    while (n--) {
        ll y;
        getline(cin, s);
        if (s.find('\'') == string::npos) {
            assert(false);
        }
        s = s.substr(s.find('\'') + 1);
        stringstream ss(s);
        ss >> y;
        // cout << s.size() << " " << y << endl;
        cout << getyear(y, s.size()) << endl;
    }

    return 0;
}