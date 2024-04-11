#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i<= n; i++) {
            printf("%d%c", i % n + 1, i == n ? '\n' : ' ');
        }
    }
}