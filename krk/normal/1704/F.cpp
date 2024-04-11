#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
const int Maxm = 205;
const int Maxp = 34;

int T;
int n;
char str[Maxn];
int nim[Maxm];

int Get(int x)
{
    if (x < Maxm) return nim[x];
    x %= Maxp;
    while (x + Maxp < Maxm) x += Maxp;
    return nim[x];
}

int main()
{
    for (int i = 1; i < Maxm; i++) {
        set <int> S;
        for (int j = 0; j <= i - 2; j++)
            S.insert(nim[j] ^ nim[i - 2 - j]);
        while (S.find(nim[i]) != S.end()) nim[i]++;
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        int st = 0;
        int xr = 0;
        for (int i = 0, j; i < n; i = j + 1) {
            j = i;
            while (j + 1 < n && str[j] != str[j + 1])
                j++;
            if ((j - i + 1) % 2)
                if (str[i] == 'R') st++;
                else st--;
            xr ^= Get(j - i + 1);
        }
        if (xr) st++;
        printf("%s\n", st > 0? "Alice": "Bob");
    }
    return 0;
}