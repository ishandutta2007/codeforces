#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[(int)1e5 + 10];
int x[(int)1e5 + 10];
/*
0 - 0
1 - 1
2 - 2
3 - 0
4 - 1
5 - 0
6 - 1
7 - 0
8 - 1
9 - 0
*/
/*
0 - 0
1 - 1
2 - 0
3 - 1
4 - 2
5 - 0
6 - 2
7 - 0
8 - 1
9 - 0
10 - 1
11 - 0
12 - 1
13 - 0
14 - 1
*/
/*
4k + 2 - 1
2k + 1 - 1
*/
int gr(int t) {
    if (k % 2 == 0) {
        if (t == 1) return 1;
        if (t == 2) return 2;
        if (t % 2 == 1) return 0;
        if (t % 2 == 0) return 1;
    }
    if (k % 2 == 1) {
        if (t == 0) return 0;
        if (t % 2 == 1) {
            if (t == 1) return 1;
            if (t == 3) return 1;
            return 0;
        }
        int a = gr(t - 1);
        int b = gr(t / 2);
        if (a > 0 && b > 0) return 0;
        if (a != 1 && b != 1) return 1;
        return 2;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    if (k % 2 == 1) k = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        x[i] = gr(a[i]);
    }
    int xr = 0;
    for (int i = 1; i <= n; i++) xr ^= x[i];
    if (xr == 0) cout << "Nicky";
    else cout << "Kevin";
    return 0;
}