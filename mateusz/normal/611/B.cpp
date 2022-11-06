#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long long a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 1; i <= 64; i++) {
        unsigned long long x = (1ULL << i) - 1;
        for (int j = 0; j < i - 1; j++) {
            unsigned long long y = x - (1ULL << j);
            if (a <= y && y <= b) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}