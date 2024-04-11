#include <bits/stdc++.h>

using namespace std;

int n;
int x[300100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x, x + n);
    cout << x[(n - 1) / 2] << endl;
}