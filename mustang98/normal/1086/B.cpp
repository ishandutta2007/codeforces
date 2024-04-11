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

int cnt[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, s;
    cin >> n >> s;
    if (n == 2) {
        cout << s << endl;
        return 0;
    }
    for (int i = 0; i + 1 < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        cnt[a]++;
        cnt[b]++;
    }
    int a = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] == 1) {
            ++a;
        }
    }
    ld ans = 2.0 * s / a;
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}