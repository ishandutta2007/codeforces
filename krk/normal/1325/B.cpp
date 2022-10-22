#include <bits/stdc++.h>
using namespace std;

int t;
int n;
set <int> S;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        S.clear();
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            S.insert(a);
        }
        printf("%d\n", int(S.size()));
    }
    return 0;
}