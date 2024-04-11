#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const string rsp = "RSP";

int T;
char str[Maxn];
int slen;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        slen = strlen(str);
        int cur[3] = {};
        for (int i = 0; i < slen; i++)
            cur[rsp.find(str[i])]++;
        int mx = 0;
        for (int i = 0; i < 3; i++)
            if (cur[i] > cur[mx]) mx = i;
        int pnt = (mx + 2) % 3;
        for (int i = 0; i < slen; i++)
            str[i] = rsp[pnt];
        printf("%s\n", str);
    }
    return 0;
}