#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string s;
    int nb = 0, ng = 0, nr = 0;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') nb++;
        else if (s[i] == 'G') ng++;
        else nr++;
    }

    bool b = 0, g = 0, r = 0;
    if (!ng && !nr || ng && nr) b = 1;
    if (!nb && !nr || nb && nr) g = 1;
    if (!nb && !ng || nb && ng) r = 1;

    if (nb && (ng > 1 || nr > 1)) b = 1;
    if (ng && (nb > 1 || nr > 1)) g = 1;
    if (nr && (nb > 1 || ng > 1)) r = 1;

    if (b) cout << 'B';
    if (g) cout << 'G';
    if (r) cout << 'R';
}