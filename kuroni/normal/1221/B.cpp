#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "WB"[(i + j) % 2];
        }
        cout << '\n';
    }
}