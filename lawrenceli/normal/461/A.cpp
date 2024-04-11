#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, a[1000100];

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n, greater<int>());
    ll sum = 0, cur = 0;
    for (int i=0; i<n; i++)
        cur += a[i], sum += cur+a[i];
    cout << sum-a[0] << endl;
}