#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
#endif

    int n; cin >> n;

    int64 lo = -oo, hi = oo;

    int64 prev = -1;

    for (int i = 0; i < n; ++i){
        int64 c, d;
        cin >> c >> d;

        if (d == 1) lo = max(lo, 1900LL);
        else hi = min(hi, 1899LL);

        lo = max(lo + c, -oo);
        hi = min(hi + c, oo);

        if (hi < lo){
            cout << "Impossible" << endl;
            return 0;
        }
    }

    if (hi >= 1000000000LL) cout << "Infinity" << endl;
    else cout << hi << endl;

    return 0;
}