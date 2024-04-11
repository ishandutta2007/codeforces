#include <bits/stdc++.h>

using namespace std;

int n;
int a[1005][1005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; i += 4) for (int j = 0; j < n; j += 4) {
        for (int k = 0; k < 4; ++k) for (int l = 0; l < 4; ++l)
            a[i+k][j+l] = s++;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}