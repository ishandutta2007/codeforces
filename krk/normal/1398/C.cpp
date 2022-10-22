#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int T;
int n;
char str[Maxn];
map <int, int> M;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        M.clear();
        scanf("%s", str + 1);
        int cur = 0;
        M[cur]++;
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            cur += str[i] - '0';
            res += M[cur - i]++;
        }
        printf("%I64d\n", res);
    }
    return 0;
}