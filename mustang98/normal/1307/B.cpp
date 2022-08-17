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

vector<int> v;

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        v.clear();
        scanf("%d%d", &n, &x);
        for (int i = 0; i < n; ++i) {
            int a;
            scanf("%d", &a);
            v.PB(a);
        }
        sort(v.begin(), v.end());
        bool fnd = false;
        for (int a : v) {
            if (a == x) {
                puts("1");
                fnd = true;
                break;
            }
        }
        if (fnd) {
            continue;
        }
        int mx = v.back();
        if (mx > x) {
            puts("2");
            continue;
        }
        int ans = x / mx;
        if (x % mx) {
            ++ans;
        }
        printf("%d\n", ans);
    }

    return 0;
}