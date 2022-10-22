#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll lim = 1000000000000ll;
const int Inf = 1000000;

vector <ll> V;
int T;
ll n;

int main()
{
    V.push_back(6);
    for (int i = 4; V.back() * i <= lim; i++) {
        ll nw = V.back() * i;
        V.push_back(nw);
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d", &n);
        int res = Inf;
        for (int i = 0; i < 1 << int(V.size()); i++) {
            ll sum = 0;
            int cnt = 0;
            for (int j = 0; j < V.size(); j++) if (i & 1 << j) {
                sum += V[j];
                cnt++;
            }
            if (sum > n) continue;
            res = min(res, cnt + __builtin_popcountll(n - sum));
        }
        printf("%d\n", res);
    }
    return 0;
}