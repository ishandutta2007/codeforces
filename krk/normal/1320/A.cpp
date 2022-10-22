#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
map <int, ll> M;
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int b; scanf("%d", &b);
        M[b - i] += b;
    }
    for (auto it: M)
        res = max(res, it.second);
    printf("%I64d\n", res);
    return 0;
}