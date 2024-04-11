#include<bits/stdc++.h>
using namespace std;
int const nax = 1e5 + 10;

int n;
int64_t tar;
char s[nax];

int get(char x) {
    return 1 << (x - 'a');
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> tar >> s + 1;

    tar -= get(s[n]);
    tar += get(s[n - 1]);

    int64_t x = 0;

    n -= 2;

    for (int i = 1 ; i <= n ; ++ i) {
        x += get(s[i]);
    }

    x -= tar;

    sort(s + 1, s + 1 + n, greater <char>());

    for (int i = 1 ; i <= n ; ++ i) {
        int y = get(s[i]) << 1;
        if (x >= y) x -= y;
    }


    cout << ((x == 0) ? "YES" : "NO");
}
/*
    Good Luck
        -Lucina
*/