#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
char s[N];

bool work() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    if (n & 1) return false;
    int w = 0, q = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') w ++;
        else if (s[i] == ')') w--;
        else q++;
    }
    int l = (q - w) / 2, r = (q + w) /2;
    if (l < 0 || r < 0) return false;
    int v = 0, ml = n + 1;
    bool swapok = false;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') v++;
        else if (s[i] == ')') v--;
        else {
            if (l > 0) v++, ml = v, l--;
            else {
                v--;
                if (ml > 1) swapok = true;
                ml = -1;
            }
        }
        ml = min(ml, v);
        if (v < 0) return false;
    }
    if (v != 0) return false;
    return !swapok;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) puts (work() ? "YES" : "NO");
}