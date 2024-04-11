#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int T;
char str[Maxn];
int slen;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        slen = strlen(str);
        int best = Maxn;
        for (int i = 0; i <= slen; i++) {
            int cnt1[2] = {};
            int cnt2[2] = {};
            for (int j = 0; j < slen; j++)
                if (j < i) cnt1[str[j] - '0']++;
                else cnt2[str[j] - '0']++;
            best = min(best, min(cnt1[0] + cnt2[1], cnt1[1] + cnt2[0]));
        }
        printf("%d\n", best);
    }
    return 0;
}