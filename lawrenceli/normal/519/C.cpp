#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    while (1) {
        if (!a || !b || a+b < 3) break;
        if (a>b) a-=2, b--;
        else a--, b-=2;
        ans++;
    }
    cout << ans;
}