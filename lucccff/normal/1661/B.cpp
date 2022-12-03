#include <bits/stdc++.h>
using namespace std;

int a[100010], st[100010], b[100010];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(time(0));
    int n;
    cin >> n;
    st[0] = 0;
    a[0] = 1;
    int x = 0, y = 1;
    while (x < y) {
        int z = y;
        for(int i = x; i < y; i++) {
            int k = st[i];
            if (a[(k + 32767) & 32767] == 0) {
                a[(k + 32767) & 32767] = 1;
                st[z++] = (k + 32767) & 32767;
                b[(k + 32767) & 32767] = b[k] + 1;
            }
            if ((k & 1) == 0) {
                if (a[k >> 1] == 0) {
                    a[k >> 1] = 1;
                    st[z++] = k >> 1;
                    b[k >> 1] = b[k] + 1;
                }
                if (a[(k >> 1) + 16384] == 0) {
                    a[(k >> 1) + 16384] = 1;
                    st[z++] = (k >> 1) + 16384;
                    b[(k >> 1) + 16384] = b[k] + 1;
                }
            }
        }
        x = y;
        y = z;
    }
    int k;
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> k;
        cout << b[k] << ' ';
    }
    return 0;
}