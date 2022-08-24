#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 10;
bool used[maxN];
int a, b, pt, c;
int main() {
    cin >> a >> b >> c;
    int pt = 1;
    while (!used[a]) {
        used[a] = true;
        int t = (10 * a) / b;
        if (t == c) {
            cout << pt;
            return 0;
        }
        pt++;
        a = (10 * a) % b;
    }
    cout << -1;
    return 0;
}