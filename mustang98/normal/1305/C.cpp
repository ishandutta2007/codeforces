#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

int a[max_n];
int cnt[max_n];
int cntd[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    if (n > 2000) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll ans = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans *= abs(a[i] - a[j]);
            ans %= m;
        }
    }
    cout << ans << endl;


    return 0;
}