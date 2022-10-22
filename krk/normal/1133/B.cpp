#include <bits/stdc++.h>
using namespace std;

const int Maxk = 105;

int n, k;
int vals[Maxk];
int res;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        vals[a % k]++;
    }
    for (int i = 0; i < k; i++) {
        int oth = (k - i) % k;
        if (i > oth) continue;
        if (i == oth) res += vals[i] / 2;
        else res += min(vals[i], vals[oth]);
    }
    cout << 2 * res << endl;
    return 0;
}