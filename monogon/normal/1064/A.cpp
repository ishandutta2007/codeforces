
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int a[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    cout << max(0, a[2] - a[1] - a[0] + 1) << endl;
}