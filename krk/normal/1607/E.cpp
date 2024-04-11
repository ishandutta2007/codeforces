#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

int T;
int n, m;
char str[Maxn];
int slen;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        scanf("%s", str);
        slen = strlen(str);
        int r = 0, c = 0;
        int mnr = 0, mxr = 0, mnc = 0, mxc = 0;
        for (int i = 0; i < slen; i++) {
            if (str[i] == 'L') c--;
            else if (str[i] == 'R') c++;
            else if (str[i] == 'D') r++;
            else r--;
            int nmnr = min(mnr, r);
            int nmxr = max(mxr, r);
            int nmnc = min(mnc, c);
            int nmxc = max(mxc, c);
            if (nmxr - nmnr + 1 > n || nmxc - nmnc + 1 > m) break;
            mnr = nmnr;
            mxr = nmxr;
            mnc = nmnc;
            mxc = nmxc;
        }
        r = 1 - mnr;
        c = 1 - mnc;
        printf("%d %d\n", r, c);
    }
    return 0;
}