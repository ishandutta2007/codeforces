#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
char s[nax], a[nax], b[nax];
int n;

void solve () {
    scanf("%d", &n);
    scanf("%s", s + 1);

    bool eq = true;

    if (s[1] == '1') {
        a[1] = '2';
        b[1] = '2';
    } else if (s[1] == '0') {
        a[1] = '2';
        b[1] = '1';
        eq = false;
    } else if (s[1] == '2') {
        a[1] = '1';
        b[1] = '1';
    }

    for (int i = 2 ; i <= n;  ++ i) {
        if (s[i] == '1') {
            if (eq) {
                a[i] = '1';
                b[i] = '0';
                eq = false;
            } else {
                a[i] = '0';
                b[i] = '1';
            }
        } else if (s[i] == '0') {
            a[i] = '0';
            b[i] = '0';
        } else if (s[i] == '2') {
            if (!eq) {
                a[i] = '0';
                b[i] = '2';
            } else {
                a[i] = '1';
                b[i] = '1';
            }
        }
    }

    a[n + 1] = 0;
    b[n + 1] = 0;
    puts(a + 1);
    puts(b + 1);
}


int main () {
    int T;

    for(scanf("%d", &T) ; T -- ; ) {
        solve ();
    }
}