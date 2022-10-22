#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int a[Maxn];
map <ll, int> M;
int res;

int main()
{
    scanf("%d", &n);
    M[0] = 1;
    int lst = 1;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        auto it = M.find(sum);
        if (it != M.end())
            if (it->second >= lst) {
                res++;
                lst = i;
            }
        M[sum] = i + 1;
    }
    printf("%d\n", res);
    return 0;
}