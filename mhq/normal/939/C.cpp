#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 10;
int a[2 * maxN];
int s, f;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    int cursum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cursum += a[i];
        a[i + n] = a[i];
    }
    cin >> s >> f;
    f--;
    int opt = cursum;
    int h = 1;
    int l = 1;
    int r = f - s + 1;
    for (int i = 1; i <= n; i++) {
        cursum -= a[l];
        cursum += a[r + 1];
        l++;
        r++;
        if (cursum > opt) {
            opt = cursum;
            h = (n + s + 1 - l) % n;
            if (h == 0) h = n;
        }
        else if (cursum == opt) {
            int nh = (n + s + 1 - l) % n;
            if (nh == 0) nh = n;
            h = min(nh, h);
        }
    }
    cout << h;
    return 0;
}