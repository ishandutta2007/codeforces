#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n;
int64_t a[nax];

/**

    insert minimum number such that prefix sum are all different


    we can minus it with INT MAX or something

9
-1 1 -1 1 -1 1 1 -1 -1
-1 INF 1 INF -1 INF 1 INF -1 INF 1 1 -1 -1
*/

int main() {
    scanf("%d", &n);

    set <int64_t> setik;
    int64_t sum = 0;
    int ans = 0;

    setik.insert(0);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%lld", a + i);
        sum += a[i];

        if (setik.count(sum)) {
            ans += 1;
            setik.clear();
            sum = a[i];
            setik.insert(0);
            setik.insert(sum);
        } else setik.insert(sum);
    }

    printf("%d\n", ans);
}