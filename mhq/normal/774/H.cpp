#include <bits/stdc++.h>
using namespace std;
const int maxN = 2005;
int n;
int c[maxN];
string s;
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    int prv = 0;
    for (int i = n; i >= 1; i--) {
        int ind = -1;
        for (int j = n; j >= 1; j--) {
            if (c[j] > 0) {
                ind = j;
                break;
            }
        }
        if (ind == -1) {
            cout << s;
            return 0;
        }
        for (int j = 1; j <= c[ind]; j++) {
            prv = 1 - prv;
            for (int k = 1; k <= ind; k++) {
                s += (char)('a' + prv);
            }
        }
        for (int j = 1; j <= ind; j++) {
            c[j] -= (ind - j + 1) * c[ind];
        }
    }
    cout << s;
    return 0;
}