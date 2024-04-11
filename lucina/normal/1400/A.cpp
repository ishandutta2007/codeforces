#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

void solve() {
    int n;
    scanf("%d", &n);
    static char s[nax];
    scanf("%s", s);
    for (int i = 0 ; i < n * 2 - 1 ; i += 2)
        putchar(s[i]);
    puts("");
}

int main() {
    int T;

    for (cin >> T ; T -- ; ) {
        solve();
    }
}