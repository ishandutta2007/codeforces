#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

vector<ll> a, b;

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while(T--) {
        a.clear();
        b.clear();
        int n;
        scanf("%d", &n);
        for (int i = 0; i < 2* n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            x = abs(x);
            y = abs(y);
            if (x == 0) {
                a.PB(y);
            } else {
                b.PB(x);
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        //reverse(a.begin(), a.end());
        ld ans = 0 ;
        for (int i = 0; i < a.size(); ++i) {
            ans += sqrt(a[i] * a[i] + b[i] * b[i]);
        }
        cout << fixed << setprecision(15) << ans << endl;
    }

    return 0;
}