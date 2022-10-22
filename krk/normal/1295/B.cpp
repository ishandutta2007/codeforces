#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int T;
int n, x;
char str[Maxn];
ll my[Maxn];

ll Get()
{
    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll nd = x - my[i];
        if (my[n] == 0) {
            if (nd == 0) return -1ll;
        } else if (nd % my[n] == 0) {
            nd /= my[n];
            if (nd >= 0) res++;
        }
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &x);
        scanf("%s", str);
        my[0] = 0;
        for (int i = 0; i < n; i++)
            my[i + 1] = my[i] + (str[i] == '0'? 1: -1);
        printf("%lld\n", Get());
    }
    return 0;
}