#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

int q, x;
ll cur[Maxn];
set <ll> S;

int main()
{
    scanf("%d %d", &q, &x);
    for (int i = 0; i < x; i++) {
        cur[i] = i;
        S.insert(cur[i]);
    }
    while (q--) {
        int num; scanf("%d", &num);
        num %= x;
        S.erase(cur[num]);
        cur[num] += x;
        S.insert(cur[num]);
        printf("%I64d\n", *S.begin());
    }
    return 0;
}