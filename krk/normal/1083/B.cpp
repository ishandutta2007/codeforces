#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const int Inf = 2000000000;

int n, k;
char A[Maxn], B[Maxn];
ll res;

int main()
{
    scanf("%d %d", &n, &k);
    scanf("%s", A);
    scanf("%s", B);
    int cur = 1;
    for (int i = 0; i < n; i++) {
        cur = min(2ll * ll(cur), ll(Inf));
        if (A[i] == 'b') cur--;
        if (B[i] == 'a') cur--;
        res += min(cur, k);
    }
    cout << res << endl;
    return 0;
}