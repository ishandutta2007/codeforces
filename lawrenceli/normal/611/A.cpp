#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <ios>

using namespace std;

void go1(int x) {
    int ans = 0;
    int c = 4;
    for (int i = 0; i < 366; i++) {
        if (c == x) ans++;
        c = (c+1)%7;
    }

    cout << ans << '\n';
}

int ar[20] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void go2(int x) {
    int ans = 0;
    for (int i = 0; i < 12; i++)
        if (x <= ar[i]) ans++;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);

    int x;
    string s, t;
    cin >> x >> s >> t;
    if (t == "week") go1(x-1);
    else go2(x);
}