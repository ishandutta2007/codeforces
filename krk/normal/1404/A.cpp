#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int T;
int n, k;
char str[Maxn];
bool one[Maxn], zer[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        scanf("%s", str);
        fill(one, one + k, false);
        fill(zer, zer + k, false);
        for (int i = 0; i < n; i++)
            if (str[i] == '1') one[i % k] = true;
            else if (str[i] == '0') zer[i % k] = true;
        bool ok = true;
        int ones = 0, zers = 0;
        for (int i = 0; i < k && ok; i++)
            if (one[i] && zer[i]) ok = false;
            else if (one[i]) ones++;
            else if (zer[i]) zers++;
        if (ones > k / 2 || zers > k / 2)
            ok = false;
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}