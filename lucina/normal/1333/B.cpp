#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, a[nax], b[nax];

bool solve () {
    scanf("%d", &n);

    // multiset<int> setik;

    bool found_pos = false, found_neg = false;

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
    }

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", b + i);
    }

    for (int i = 1 ; i <= n ; ++ i) {

        if (a[i] == b[i]) {
           
        } else if (a[i] < b[i]) {
            if (!found_pos) return false;
        } else if (a[i] > b[i]) {
            if (!found_neg) return false;
        } else throw;

        if (a[i] > 0) found_pos = true;
        if (a[i] < 0) found_neg = true;

    }

    return true;
}

int main () {
    int T;

    for (cin >> T ; T -- ;)
        puts(solve() ? "YES" : "NO");
}
/*
    Good Luck
        -Lucina
*/