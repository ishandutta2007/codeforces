#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        set <int> S;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            S.insert(a);
        }
        printf("%d\n", *S.rbegin() - *S.begin());
    }
    return 0;
}