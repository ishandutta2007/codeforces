#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int L[Maxn], R[Maxn];
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &L[i], &R[i]);
    sort(L, L + n); sort(R, R + n);
    res += n;
    for (int i = 0; i < n; i++)
        res += max(L[i], R[i]);
    cout << res << endl;
    return 0;
}