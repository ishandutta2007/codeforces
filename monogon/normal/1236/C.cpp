
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n * (n / 2); j += n) {
            cout << j + 1 << " ";
        }
        for(int j = n - i - 1 + n * (n / 2); j < n * n; j += n) {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}