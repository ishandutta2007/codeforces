#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
char s[nax];
int x;

void solve() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    scanf("%d", &x);
    static int a[nax];
    static int b[nax];
    for (int i = 1 ; i <= n; ++ i)
        a[i] = s[i] - '0';
    fill(b, b + 1 + n, -1);

    auto no = [&] () -> void{
        puts("-1");
    };

    for (int i = 1 ; i <= n;  ++ i) {
        if (a[i] == 0) {
            if (i - x > 0) {
                if (b[i - x] == 1) return no();
                b[i - x] = 0;
            }
            if (i + x <= n)
                if (b[i + x] == 1) return no();
                else b[i + x] = 0;
        }
    }

    for (int i = 1 ; i <= n ; ++ i) {
        if (b[i] == -1) b[i] = 1;
    }

    for (int i = 1 ; i <= n; ++ i) {
        if (a[i] == 1) {
            bool ok = false;
            ok |= (i - x > 0 && b[i - x] == 1);
            ok |= (i + x <= n && b[i + x] == 1);
            if (!ok) return no();
        }
    }

    for (int i = 1 ; i <= n ; ++ i) {
        if (b[i] == -1) b[i] = 1;
        putchar(b[i] + '0');
    }
    puts("");
}

int main() {
    int T;

    for (cin >> T ;  T --; ) {
        solve();
    }
}