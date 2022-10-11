#include <bits/stdc++.h>
using namespace std;

const int N = 4E4;

int t, n, pos[N];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        pos[0] = 0;
        for (int i = N - 1; i >= 1; i--) {
            int cur = i * (i + 1) / 2;
            pos[i] = n / cur;
            n %= cur;
        }
        putchar('1');
        for (int i = 0; i < N; i++) {
            putchar('3');
            while (pos[i]--) {
                putchar('7');
            }
        }
        putchar('\n');
    }
}