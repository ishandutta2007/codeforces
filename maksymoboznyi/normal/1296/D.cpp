#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const int N = 2e5 + 5;

int n, a, b, k, p[N], need[N];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a >> b >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        int del = p[i] % (a + b);
        if (del == 0)
            del = a + b;
        if (del <= a)
            continue;
        int nkol = (del - 1) / a + 1;
        need[i] = nkol - 1;
    }
    sort(need + 1, need + n + 1);
    for (int i = 1; i <= n; i++)
        if (need[i] > k) {
            cout << i - 1;
            return 0;
        } else k -= need[i];
    cout << n;
    return 0;
}