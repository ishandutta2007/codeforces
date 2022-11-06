#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 5e5 + 5;

int n, l, r, p[N];



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> l >> r;
        //cout << n << endl;
        p[1] = 2 * (n - 1);
        for (int i = 2; i < n; i++)
            p[i] = p[i - 1] + (n - i) * 2;
        p[n] = p[n - 1] + 1;
        int cur_p = 1;
        for (int i = l; i <= r; i++) {
            //cout << i << endl;
            if (i == n * (n - 1) + 1) {
                cout << 1;
                continue;
            }
            while (p[cur_p] < i)
                cur_p++;
            if (i % 2 == 1) {
                cout << cur_p << ' ';
            } else {
                int del = i - p[cur_p - 1];
                //cout << '*' << del << ' ' << cur_p << endl;
                cout << del / 2 + cur_p << ' ';
            }
        }
        cout << "\n";
    }
    return 0;
}