#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 100000000000ll;
const int Maxn = 105;

vector <ll> fib, sum;
int T;
int k;
int c[Maxn];
int a[Maxn];

bool Check(int ind, int lst)
{
    a[lst] -= fib[ind];
    if (ind == 0) return true;
    ind--;
    for (int j = 0; j < k; j++) if (j != lst)
        if (a[j] >= fib[ind])
            if (Check(ind, j)) return true;
    ind++;
    a[lst] += fib[ind];
    return false;
}

bool Solve(int ind, int lst)
{
    for (int i = 0; i < k; i++)
        a[i] = c[i];
    if (a[lst] < fib[ind]) return false;
    return Check(ind, lst);
}

int main()
{
    fib.push_back(1);
    sum.push_back(1);
    fib.push_back(1);
    sum.push_back(2);
    while (sum.back() < Inf) {
        ll nw = fib.back() + fib[int(fib.size()) - 2];
        fib.push_back(nw);
        sum.push_back(sum.back() + nw);
    }
    scanf("%d", &T);
    while (T--) {
        ll nd = 0;
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &c[i]);
            nd += c[i];
        }
        int ind = lower_bound(sum.begin(), sum.end(), nd) - sum.begin();
        if (sum[ind] != nd) { printf("NO\n"); continue; }
        bool ok = false;
        for (int i = 0; i < k; i++)
            if (Solve(ind, i)) {
                ok = true;
                break;
            }
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}