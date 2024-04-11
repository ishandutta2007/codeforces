#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxm = 20000005;
const int Maxk = 21;
const int Maxn = 1000005;

int n, m;
bool was[Maxm];
int cur;
int f[Maxk];
bool ign[Maxn];
ll res;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i < Maxk; i++) {
        for (int j = 1; j <= m; j++) if (!was[i * j]) {
            was[i * j] = true;
            cur++;
        }
        f[i] = cur;
    }
    res = 1;
    for (int i = 2; i <= n; i++) if (!ign[i]) {
        int cnt = 1, my = i;
        while (my <= n / i) {
            my *= i;
            ign[my] = true;
            cnt++;
        }
        res += f[cnt];
    }
    cout << res << endl;
    return 0;
}