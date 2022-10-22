#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxl = 26;

char str[Maxn];
int slen;
vector <int> V[Maxn];
int freq[Maxl];
int n;

int main()
{
    scanf("%d", &slen);
    scanf("%s", str);
    for (int i = 0; i < slen; i++)
        V[str[i] - 'a'].push_back(i + 1);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str); slen = strlen(str);
        fill(freq, freq + Maxl, 0);
        for (int j = 0; j < slen; j++)
            freq[str[j] - 'a']++;
        int res = 0;
        for (int i = 0; i < Maxl; i++) if (freq[i] > 0)
            res = max(res, V[i][freq[i] - 1]);
        printf("%d\n", res);
    }
    return 0;
}