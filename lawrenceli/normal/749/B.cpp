#include <bits/stdc++.h>

using namespace std;

int x[3], y[3];

int main() {
    for (int i = 0; i < 3; i++) cin >> x[i] >> y[i];
    cout << "3\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            if (i != j) {
                for (int k = 0; k < 3; k++)
                    if (k != i && k != j) {
                        cout << x[j] + x[k] - x[i] << ' ' << y[j] + y[k] - y[i] << endl;
                    }
                break;
            }
    }
}