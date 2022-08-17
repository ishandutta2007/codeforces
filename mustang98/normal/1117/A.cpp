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

int m[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int mx = -1;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
        mx = max(mx, m[i]);
    }
    int ans = 1;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (m[i] == mx) {
            ++cur;
            ans = max(ans, cur);
        } else {
            cur = 0;
        }
    }
    cout << ans << endl;
    return 0;
}