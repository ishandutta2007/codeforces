#include <bits/stdc++.h>
using namespace std;
int h1, a1, c1;
int h2, a2;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> h1 >> a1 >> c1;
    cin >> h2 >> a2;
    int x1 = 30000;
    int x2 = 30000;
    for (int i = 0; i <= 10000; i++) {
        for (int j = 0; j <= 10000; j++) {
            if (h2 - i * a1 <= 0 && h1 + j * c1 - (i + j - 1) * a2 > 0) {
                if (x1 + x2 > i + j) {
                    x1 = i;
                    x2 = j;
                }
            }
        }
    }
    cout << x1 + x2 << '\n';
    for (int i = 0; i < x2; i++) {
        cout << "HEAL" << '\n';
    }
    for (int i = 0; i < x1; i++) {
        cout << "STRIKE" << '\n';
    }
	return 0;
}