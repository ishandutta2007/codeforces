#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxl = 26;

int T;
char str[Maxn];
int slen;
int freq[Maxl];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        slen = strlen(str);
        fill(freq, freq + Maxl, 0);
        for (int i = 0; i < slen; i++)
            freq[str[i] - 'a']++;
        int pnt = 0;
        while (freq[str[pnt] - 'a'] > 1) {
            freq[str[pnt] - 'a']--;
            pnt++;
        }
        printf("%s\n", str + pnt);
    }
    return 0;
}