#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 3005;
const int mod = 1000000007;

int pw3[Maxn];
int k, m;
int lh[Maxn][Maxn], rh[Maxn][Maxn];
char s[Maxn];
int len;
int H1[Maxn], H2[Maxn];
int res[Maxn];

void Init(int k)
{
    if (lh[k][0] != -1) return;
    if (k == 1) { lh[k][0] = rh[k][0] = 0; }
    else if (k == 2) { lh[k][0] = rh[k][0] = 1; }
    else {
        Init(k - 1); Init(k - 2);
        int i = 0;
        while (i < Maxn && lh[k - 1][i] != -1) { lh[k][i] = lh[k - 1][i]; i++; }
        int j = 0;
        while (i + j < Maxn && lh[k - 2][j] != -1) {
            lh[k][i + j] = (lh[k - 1][i - 1] + ll(pw3[i]) * ll(lh[k - 2][j]) % ll(mod)) % mod;
            j++;
        }
        i = 0;
        while (i < Maxn && rh[k - 2][i] != -1) { rh[k][i] = rh[k - 2][i]; i++; }
        j = 0;
        while (i + j < Maxn && rh[k - 1][j] != -1) {
            rh[k][i + j] = (rh[k - 1][j] + ll(pw3[j + 1]) * ll(rh[k - 2][i - 1]) % ll(mod)) % mod;
            j++;
        }
    }
}

int getRes(int k)
{
    if (k == 1) return len == 1 && s[0] == 'a';
    if (k == 2) return len == 1 && s[0] == 'b';
    if (res[k] == -1) {
        res[k] = (getRes(k - 1) + getRes(k - 2)) % mod;
        for (int i = 0; i < len - 1; i++)
            res[k] = (res[k] + (rh[k - 1][i] == H1[i] && lh[k - 2][len - i - 2] == H2[len - i - 2])) % mod;
    }
    return res[k];
}

int main()
{
    pw3[0] = 1;
    for (int i = 1; i < Maxn; i++) pw3[i] = ll(pw3[i - 1]) * 3LL % ll(mod);
    fill((int*)lh, (int*)lh + Maxn * Maxn, -1); fill((int*)rh, (int*)rh + Maxn * Maxn, -1);
    scanf("%d %d", &k, &m);
    Init(k);
    while (m--) {
        scanf("%s", s); len = strlen(s);
        H1[0] = s[0] - 'a';
        for (int i = 1; i < len; i++) H1[i] = (H1[i - 1] + ll(pw3[i]) * ll(s[i] - 'a') % ll(mod)) % mod;
        H2[0] = s[len - 1] - 'a';
        for (int i = 1; i < len; i++) H2[i] = (s[len - 1 - i] - 'a' + 3LL * ll(H2[i - 1]) % ll(mod)) % mod;
        fill(res, res + k + 1, -1);
        printf("%d\n", getRes(k));
    }
    return 0;
}