#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 998244353;

int n;
char str[Maxn];
char L[Maxn], R[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++) {
        L[i] = str[i];
        if (i > 1 && L[i - 1] != L[i])
            L[i] = '?';
    }
    for (int i = n; i > 0; i--) {
        R[i] = str[i];
        if (i + 1 <= n && R[i] != R[i + 1])
            R[i] = '?';
    }
    L[0] = 'a';
    for (int i = 1; i <= n && L[i - 1] != '?'; i++) {
        int lef = i, rig = n;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if ((i == 1 || L[i - 1] != '?') &&
                (mid == n || R[mid + 1] != '?') &&
                (i == 1 || mid == n || L[i - 1] == R[mid + 1]))
                rig = mid - 1;
            else lef = mid + 1;
        }
        res = (res + (n + 1 - lef)) % mod;
    }
    printf("%d\n", res);
    return 0;
}