#include <bits/stdc++.h>
using namespace std;



bool work() {
    int a[4], have;
    cin >> have;
    for (int i = 1; i <= 3; i++) {
        cin >> a[i];
    }
    if (a[have] == 0 || a[a[have]] == 0) return false;
    else return true;
}

int main () {
    int T;
    cin >> T;
    while (T--) puts(work() ? "YES" : "NO");
}