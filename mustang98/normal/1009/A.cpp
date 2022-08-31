#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1200, inf = 1000111222;

int c[max_n];
int a[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    int c1 = 0, c2 = 0;
    while (c1 < n && c2 < m) {
        if (a[c2] >= c[c1]) {
            ++ans;
            ++c2;
        }
        ++c1;
    }
    cout << ans;

    return 0;
}