#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;


int main() {
    int T;

    for (cin >> T ; T -- ;) {
        int n, m;
        cin >> n >> m;
        static int a[nax];
        for (int i = 1 ; i <= n ; ++ i) {
            scanf("%d", a + i);
        }
        if (accumulate(a + 1, a + 1 + n, 0LL) == m) {
            puts("YES");
        } else puts("NO");
    }
}