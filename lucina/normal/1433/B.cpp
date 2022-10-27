#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

/*
int c2(int a) {
    return a * (a + 1) / 2;
}

int f(int a, int b) {
    int from = b - a;
    return c2(b) - c2(from);
}
*/
int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        int n;
        static int a[256];
        cin >> n;

        for (int i = 1 ; i <= n ; ++ i)
            cin >> a[i];

        int f = find(a + 1, a + 1 + n, 1) - a;
        int lst = -1;
        for (int i = 1 ; i <= n ; ++ i)
            if (a[i] == 1) lst = i;


        int bar = accumulate(a + f , a + lst + 1, 0);
        cout << lst - f + 1 - bar << '\n';
/*
        int b = 0;
        int s = 0;
        int x = 0;

        for (int i = 1 ; i <= n ; ++ i) {
            cin >> a[i];
            if (a[i] == 1) s += i, x += 1;
        }

        int ans = INT_MAX;

        int cnt = 0;

        for (int i = 1 ; i <= n ; ++ i) {
            if (a[i] == 1) {
                s -= i;
                int w = cnt * i - cnt * (cnt + 1) / 2;
                int res = x - cnt - 1;
                int y = (i * res) + (res * (res + 1)) / 2;
                ans = min(ans, w - b + s - y);
                b += i;
                cnt += 1;
            }
        }

        cout << ans << '\n';
*/
    }
}