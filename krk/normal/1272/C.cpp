#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxl = 26;

int n, k;
bool ok[Maxl];
char str[Maxn];
ll res;

int main()
{
    scanf("%d %d", &n, &k);
    scanf("%s", str);
    for (int i = 0; i < k; i++) {
        char ch; scanf(" %c", &ch);
        ok[ch - 'a'] = true;
    }
    for (int i = 0; i < n; )
        if (!ok[str[i] - 'a']) i++;
        else {
            int j = i;
            while (j < n && ok[str[j] - 'a']) j++;
            res += ll(j - i) * (j - i + 1) / 2ll;
            i = j;
        }
    printf("%I64d\n", res);
    return 0;
}