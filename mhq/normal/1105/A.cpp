#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector < int > a(n);
    for (int& x : a) {
        cin >> x;
    }
    int best = -1;
    int val = 100000;
    for (int i = 1; i <= 100; i++) {
        int p = 0;
        for (int x : a) {
            p += min({abs(i - 1 - x), abs(i - x), abs(i + 1 - x)});
        }
        if (p < val) {
            val = p;
            best = i;
        }
    }
    cout << best << " " << val;
    return 0;
}