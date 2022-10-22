#include <bits/stdc++.h>
using namespace std;

int n;
map <int, int> M;
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        M[a]++;
    }
    for (auto it: M)
        res = max(res, it.second);
    printf("%d\n", res);
    return 0;
}