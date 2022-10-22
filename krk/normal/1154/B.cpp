#include <bits/stdc++.h>
using namespace std;

int n;
set <int> S;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        S.insert(a);
    }
    if (S.size() == 1) printf("0\n");
    else if (S.size() == 2) {
        int d = *S.rbegin() - *S.begin();
        if (d % 2 == 0) d /= 2;
        printf("%d\n", d);
    }
    else if (S.size() == 3) {
        int a = *S.begin(); S.erase(S.begin());
        int b = *S.begin(); S.erase(S.begin());
        int c = *S.begin();
        if (b - a == c - b) printf("%d\n", b - a);
        else printf("-1\n");
    } else printf("-1\n");
    return 0;
}