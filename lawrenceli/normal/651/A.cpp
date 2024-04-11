#include <bits/stdc++.h>

using namespace std;

int main() {
    int a1, a2;
    cin >> a1 >> a2;
    for (int t = 0; 1; t++) {
        if (a1 <= 0 || a2 <= 0) {
            cout << t << '\n';
            return 0;
        }
        if (a1 > a2) swap(a1, a2);
        if (a2 == 1) t--;
        a1++, a2 -= 2;
    }
}