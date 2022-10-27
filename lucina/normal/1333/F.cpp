#include<bits/stdc++.h>
using namespace std;
int const nax = 1e6 + 10, inf = 1e9;

int n;
bool first[nax];

int ans[nax];

int main () {
    scanf("%d", &n);

    int keep = 0;

    fill(ans + 1, ans + 1 + n, inf);

    for (int i = n ; i >= 1 ; -- i) {
        /// keep the maximum number of spot we can put
        ++ keep;
        first[i] = true;

        for (int j = i + i ; j <= n ; j += i) {
            if (first[j]) {
                first[j] = false;
                -- keep;
            }
        }
        if ((i - 1) * 2 <= n)
        ans[i - 1 + keep] = min(ans[i - 1 + keep], i - 1);
    }

    for (int i = n - 1 ;i >= 2 ; -- i) {
        ans[i] = min(ans[i], ans[i + 1]);
        if (ans[i] == inf) throw;
    }

    for (int i = 2 ; i <= n ; ++ i)
        printf("%d ", ans[i]);

}


/*
    Good Luck
        -Lucina
*/