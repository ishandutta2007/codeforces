#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n, x;
multiset <ll> S;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &x);
        S.clear();
        for (int i = 0; i < n; i++) {
            ll a; scanf("%I64d", &a);
            S.insert(a);
        }
        int res = 0;
        while (!S.empty()) {
            ll num = *S.begin(); S.erase(S.begin());
            auto it = S.find(num * x);
            if (it == S.end()) res++;
            else S.erase(it);
        }
        printf("%d\n", res);
    }
    return 0;
}