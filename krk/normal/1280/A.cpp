#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxl = 1000005;
const int mod = 1000000007;

int T;
int x;
char str[Maxl];
int slen, rlen;

void Add(int st, int per, ll hm)
{
    while (slen < x && hm > 0) {
        hm--;
        slen++;
        str[slen] = str[(slen - st) % per + st];
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &x);
        scanf("%s", str + 1);
        slen = strlen(str + 1);
        rlen = slen;
        int l = 0;
        while (l < x) {
            l++;
            int per = (rlen - l + mod) % mod;
            rlen = (rlen + ll(per) * (ll(str[l] - '0') - 1ll)) % mod;
            Add(l + 1, per, ll(per) * (ll(str[l] - '0') - 1ll));
        }
        printf("%d\n", rlen);
    }
    return 0;
}