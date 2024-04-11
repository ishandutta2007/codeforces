#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
const string bad = ":(";

int slen;
char str[Maxn];

int main()
{
    scanf("%d", &slen);
    scanf("%s", str);
    if (slen % 2) { printf("%s\n", bad.c_str()); return 0; }
    int op = slen / 2, cl = slen / 2;
    for (int i = 0; i < slen; i++)
        if (str[i] == '(') op--;
        else if (str[i] == ')') cl--;
    if (op < 0 || cl < 0) { printf("%s\n", bad.c_str()); return 0; }
    for (int i = 0; i < slen; i++) if (str[i] == '?')
        if (op > 0) { str[i] = '('; op--; }
        else { str[i] = ')'; cl--; }
    int st = 0;
    for (int i = 0; i + 1 < slen; i++) {
        if (str[i] == '(') st++;
        else st--;
        if (st <= 0) { printf("%s\n", bad.c_str()); return 0; }
    }
    printf("%s\n", str);
    return 0;
}