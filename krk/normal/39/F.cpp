#include <iostream>
using namespace std;

const int Maxn = 105;

int n, m, k;
int d[Maxn], p[Maxn];
int best = Maxn, res[Maxn], len;

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) cin >> d[i];
    for (int i = 1; i <= k; i++) cin >> p[i];
    for (int i = 1; i <= m; i++) {
        int cur = 0;
        for (int j = 1; j <= k; j++) cur += p[j] % d[i] == 0;
        if (cur < best) { best = cur; res[0] = i; len = 1; }
        else if (cur == best) res[len++] = i;
    }
    cout << len << endl;
    for (int i = 0; i < len; i++)
        cout << res[i] << (i + 1 < len? " ": "\n");
    return 0;
}