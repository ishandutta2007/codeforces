#include <bits/stdc++.h>

using namespace std;

int ar[100100];

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int l = 1, r = n, b = 0;
    for (int i=0; i<n; i++) {
        if (!b) ar[i] = l++;
        else ar[i] = r--;
        b = !b;
    }
    if (k%2 == 1) {
        sort(ar+k, ar+n);
    } else {
        sort(ar+k, ar+n); reverse(ar+k, ar+n);
    }
    for (int i=0; i<n; i++) cout << ar[i] << ' ';
}