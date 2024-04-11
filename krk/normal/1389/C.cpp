#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxl = 10;

int T;
char str[Maxn];
int slen;
int freq[Maxl];

int Get(char a, char b)
{
    int res = 0;
    for (int i = 0; i < slen; i++)
        if (str[i] == a) {
            res++;
            swap(a, b);
        }
    return res / 2 * 2;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str); slen = strlen(str);
        fill(freq, freq + Maxl, 0);
        for (int i = 0; i < slen; i++)
            freq[str[i] - '0']++;
        int mx = 0;
        for (int i = 0; i < Maxl; i++)
            mx = max(mx, freq[i]);
        for (char a = '0'; a <= '9'; a++)
            for (char b = '0'; b <= '9'; b++) if (a != b)
                mx = max(mx, Get(a, b));
        printf("%d\n", slen - mx);
    }
    return 0;
}