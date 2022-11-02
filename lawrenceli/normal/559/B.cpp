#include <bits/stdc++.h>
using namespace std;

const int maxn = 200100;

int n;
char s[maxn], t[maxn];

bool eq(int l1, int r1, int l2, int r2) {
    for (int i=0; i<r1-l1; i++)
        if (s[i+l1] != t[i+l2])
            return 0;
    return 1;
}

bool good(int l1, int r1, int l2, int r2) {
    assert(r1-l1 == r2-l2);
    if (eq(l1, r1, l2, r2)) return 1;
    if ((r1-l1)%2) return 0;
    int m1 = (l1+r1)/2, m2 = (l2+r2)/2;
    return good(l1, m1, l2, m2) && good(m1, r1, m2, r2) || good(l1, m1, m2, r2) && good(m1, r1, l2, m2);
} 

int main() {
    ios_base::sync_with_stdio(0);

    cin >> s >> t;
    n = strlen(s);
    if (good(0, n, 0, n)) cout << "YES";
    else cout << "NO";
}