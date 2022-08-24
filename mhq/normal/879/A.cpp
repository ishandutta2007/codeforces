#include <bits/stdc++.h>
using namespace std;
int n;
int s[1005];
int d[1005];
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        cin >> d[i];
    }
    int curind = 1;
    for (int i = 1; i <= 1000 * 1000 + 10; i++) {
        if ((i % d[curind]) == (s[curind] % d[curind])) {
            if (i >= s[curind]) {
                curind++;
                if (curind == (n + 1)) {
                    cout << i;
                    return 0;
                }
            }
        }
    }
    return 0;
}