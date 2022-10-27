#include<bits/stdc++.h>
using namespace std;
int n, k;

void solve() {
    cin >> n >> k;

    for (int i = 0 ; i < n ; ++ i) {
        putchar('a' + (i % 3));
    }
    puts("");
}

int main() {
    int T;
    cin >> T;

    while (T --) {
        solve();
    }
}