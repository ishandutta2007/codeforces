#include <bits/stdc++.h>

using namespace std;

const int N = 100005, M = 1e9 + 7;

int charToInt(char x) {
    if (x >= '0' && x <= '9') {
        return x - 48;
    }
    if (x >= 'A' && x <= 'Z') {
        return x - 65 + 10;
    }
    if (x >= 'a' && x <= 'z') {
        return x - 97 + 36;
    }
    if (x == '-') {
        return 62;
    }
    return 63;
}

int main() {

    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;
    int n = s.size();
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int x = charToInt(s[i]);
        for (int j = 1; j <= 6; j++) {
            if (x % 2 == 0) {
                ans = (long long)ans * 3 % M;
            }
            x /= 2;
        }
    }
    printf("%d\n", ans);

    return 0;
}