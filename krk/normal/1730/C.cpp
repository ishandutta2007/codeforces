#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxd = 10;

int T;
char str[Maxn];
int slen;
int freq[Maxd];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str); slen = strlen(str);
        fill(freq, freq + Maxd, 0);
        int mn = 9;
        for (int i = slen - 1; i >= 0; i--) {
            int cur = str[i] - '0';
            if (cur > mn) freq[min(Maxd - 1, cur + 1)]++;
            else freq[cur]++;
            mn = min(mn, cur);
        }
        for (int i = 0; i < Maxd; i++)
            while (freq[i]--)
                printf("%d", i);
        printf("\n");
    }
    return 0;
}