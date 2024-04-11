#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

set <ii> S;
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        S.insert(ii(2 * i, 2 * i));
        S.insert(ii(2 * i, 2 * i + 1));
        S.insert(ii(2 * i, 2 * i + 2));
        S.insert(ii(2 * i + 1, 2 * i));
        S.insert(ii(2 * i + 1, 2 * i + 2));
        S.insert(ii(2 * i + 2, 2 * i));
        S.insert(ii(2 * i + 2, 2 * i + 1));
        S.insert(ii(2 * i + 2, 2 * i + 2));
    }
    printf("%d\n", int(S.size()));
    for (set <ii>::iterator it = S.begin(); it != S.end(); it++)
        printf("%d %d\n", it->first, it->second);
    return 0;
}