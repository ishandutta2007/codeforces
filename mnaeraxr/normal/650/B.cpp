#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("test.in", "r", stdin);
#endif

    int64 n, a, b, T;

    cin >> n >> a >> b >> T;

    string s; cin >> s;

    vector<int64> B(n + 1);

    for (int i = 0; i < n; ++i)
        B[i + 1] = B[i] + (s[i] == 'w');

    int64 best = 0;

    for (int64 i = n; i; --i){
        int64 l = -1, h = i;

        // cout << "check: " << i << endl;

        while (l + 1 < h){
            int64 m = (l + h) / 2;

            int64 wleft = B[n] - B[i];
            int64 wright = B[m + 1];
            int64 sleft = n - i;
            int64 sright = m;

            int64 value = b * (wleft + wright) + sleft + sright + 1 +
                        a * (sleft + sright + min(sleft, sright));

            // cout << m << " " << value << endl;
            // cout << wleft << " " << wright << endl;
            // cout << sleft << " " << sright << endl;

            if (value <= T)
                l = m;
            else
                h = m;
        }

        // cout << i << " " << l << endl;

        if (l != -1)
            best = max(best, n - i + l + 1);
    }


    cout << best << endl;

    return 0;
}