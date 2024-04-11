#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxl = 26;

int T;
int n, k;
char str[Maxn];
bool tk[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        scanf("%s", str);
        fill(tk, tk + Maxl, false);
        for (int i = 0; i < n; i++)
            while (str[i] != 'a' && (tk[str[i] - 'a'] || k > 0)) {
                if (!tk[str[i] - 'a']) {
                    tk[str[i] - 'a'] = true;
                    k--;
                }
                str[i]--;
            }
        printf("%s\n", str);
    }
    return 0;
}