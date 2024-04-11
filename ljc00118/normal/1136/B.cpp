#include <bits/stdc++.h>
using namespace std;

int n, k, ans;

int main() {
    cin >> n >> k;
    int minn = min(k, n - k + 1);
    ans = 5 + (minn - 1) + (n - 1) + (n - 2) * 2;
    cout << ans << endl;
    return 0;
}