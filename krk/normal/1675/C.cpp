#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
char str[Maxn];
int slen;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str); slen = strlen(str);
        int lef = 0, rig = slen - 1;
        for (int i = 0; i < slen; i++)
            if (str[i] == '1') lef = i;
            else if (str[i] == '0')
                if (rig == slen - 1) rig = i;
        printf("%d\n", rig - lef + 1);
    }
    return 0;
}