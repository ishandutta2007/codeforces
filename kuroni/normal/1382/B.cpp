#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, te, a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> te;
    while (te--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        bool ans = false;
        for (int i = n; i >= 1; i--) {
            ans = (a[i] == 1 ? !ans : true);
        }
        cout << (ans ? "First\n" : "Second\n");
    }
}