#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxl = 26;
const int Maxn = 200005;

int T;
int n, m;
char s[Maxn];
int tims[Maxn];
ll freq[Maxl];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        scanf("%s", s + 1);
        fill(tims, tims + n + 2, 0);
        for (int i = 0; i < m; i++) {
            int a; scanf("%d", &a);
            tims[a]++;
        }
        tims[n]++;
        fill(freq, freq + Maxl, 0);
        for (int i = n; i > 0; i--) {
            tims[i] += tims[i + 1];
            freq[s[i] - 'a'] += tims[i];
        }
        for (int i = 0; i < Maxl; i++)
            printf("%I64d%c", freq[i], i + 1 < Maxl? ' ': '\n');
    }
    return 0;
}