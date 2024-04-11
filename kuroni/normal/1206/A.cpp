#include <bits/stdc++.h>
using namespace std;

const int N = 205;

int n, a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int j = 0; j < 2; j++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        cout << *max_element(a + 1, a + n + 1) << " ";
    }
}