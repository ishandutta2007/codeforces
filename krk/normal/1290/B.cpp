#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;
const int Maxn = 200005;

char str[Maxn];
int slen;
int freq[Maxn][Maxl];
int q;

int main()
{
    scanf("%s", str + 1);
    slen = strlen(str + 1);
    for (int i = 1; i <= slen; i++) {
        for (int j = 0; j < Maxl; j++)
            freq[i][j] = freq[i - 1][j];
        freq[i][str[i] - 'a']++;
    }
    scanf("%d", &q);
    while (q--) {
        int l, r; scanf("%d %d", &l, &r);
        string yes = "Yes", no = "No";
        string res;
        if (l == r) res = yes;
        else if (str[l] != str[r]) res = yes;
        else {
            int cnt = 0;
            for (int i = 0; i < Maxl; i++)
                if (freq[r][i] - freq[l - 1][i] > 0) cnt++;
            res = cnt >= 3? yes: no;
        }
        printf("%s\n", res.c_str());
    }
    return 0;
}