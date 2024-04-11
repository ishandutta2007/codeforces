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

int l[max_n], r[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", l + i, r + i);
    }
    sort(l, l + n);
    sort(r, r + n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += max(l[i], r[i]);
    }
    ans += n;
    cout << ans;
    return 0;
}