#include<bits/stdc++.h>
using namespace std;
int const inf = 1e8;
int n;
int a[1 << 10];

void shift (int pos) {
    int b[3];

    b[0] = a[pos + 2];
    b[1] = a[pos];
    b[2] = a[pos + 1];

    for (int j = 0 ; j < 3 ; ++ j)
        a[pos + j] = b[j];
}

void print (vector <int> &ans) {
    printf("%d\n", int(ans.size()));
    for (int i : ans) {
        printf("%d ", i);
    }
    printf("\n");
}

void solve () {

    scanf("%d", &n);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
    }

    int inv = 0;
    vector <int> ans;

    for (int i = 1 ; i < n - 1 ; ++ i) {
        int mn = a[i];
        int pos = -1;
        for (int j = i + 1 ; j <= n ; ++ j) {
            if (a[j] < mn) {
                mn = a[j];
                pos = j;
            }
        }
        if (pos == -1) continue;
        while (pos - i >= 2) {
            ans.push_back(pos - 2);
            shift(pos - 2);
            pos -= 2;
        }

        if (pos > i) {
            ans.push_back(i);
            ans.push_back(i);
            shift(i);
            shift(i);
        }
    }


    if (is_sorted(a + 1, a + 1 + n)) {
        print(ans);
        return ;
    }
    if (a[n] == a[n - 2]) {
        shift(n - 2);
        ans.push_back(n - 2);
        return print(ans);
    }

    int pos = -1;

    for (int i = n - 2 ; i >= 1 ; -- i) {
        if (a[i] == a[i - 1]) {
            pos = i - 1;
            break;
        }
    }
    if (pos == -1) {
        puts("-1");
        return ;
    }
    //fprintf(stderr, "ALIVE pos = %d\n", pos);

    for (int i = n - 2 ; i >= pos ; -- i) {
        shift(i);
        ans.push_back(i);
    }
    assert(is_sorted(a + 1, a + 1 + n));
    print(ans);
}

/**
    find repeated value, shift until it's sorted.
    If no value repeat, number of inversion is static.

    1 1 2 3 4 9 8
    1 1 2 3 8 4 9
    1 1 2 4 3 8 9
    1 1 3 2 4 8 9
    1 2 1 3 4 8 9
    1 1 2 3 4 8 9
*/

int main () {
    //cin.tie(0)->sync_with_stdio(false);

    int T;
    for (scanf("%d", &T) ; T -- ; ) {
        solve();
    }
}
/**
1
8
8 4 5 2 3 6 7 3

*/