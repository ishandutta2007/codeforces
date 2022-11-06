#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
int b[maxn];

ll Solve(int n) {
    // int cur_max = -1;
    // int cur_pos = 0;
    // for (int i = 0; i < n; ++i)
    //     if (a[i] > cur_max) {
    //         cur_max = a[i];
    //         cur_pos = i;
    //     }
    // for (int i = cur_pos; i < n; ++i)
    //     b[i] = cur_max + 1;
    int cur_max = -1;
    for (int i = n - 1; i >= 0; --i) {
        cur_max = max(cur_max, a[i] + 1);
        b[i] = cur_max;
        --cur_max;
    }
    // for (int i = 0; i < n; ++i)
    //     cout << b[i] << ' ';
    // cout << endl;
    cur_max = b[0];
    for (int i = 0; i < n; ++i) {
        cur_max = max(cur_max, b[i]);
        b[i] = cur_max;
    }
    // for (int i = 0; i < n; ++i)
    //     cout << b[i] << ' ';
    // cout << endl;
    ll ans = 0LL;
    for (int i = 0; i < n; ++i)
        ans += 1LL * (b[i] - 1 - a[i]);
    return ans;
}

int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf ("%d", &a[i]);
    cout << Solve(n) << endl;
    return 0;
}