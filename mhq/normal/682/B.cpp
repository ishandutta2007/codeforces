#include <bits/stdc++.h>
using namespace std;

int a[222222];

int main() {
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    int mex = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= mex) mex++;
    }
    cout << mex << endl;

    return 0;
}