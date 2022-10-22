#include <bits/stdc++.h>
using namespace std;

const string digs = "0123456789ABCDEF";
const int Maxn = 5205;

bool B[Maxn][Maxn];
int n;
char str[Maxn];
int g;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        int pnt = 0;
        for (int j = 0; j < n / 4; j++) {
            int let = digs.find(str[j]);
            for (int b = 3; b >= 0; b--)
                B[i][pnt++] = bool(let & 1 << b);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int l = 0, r; l < n; l = r) {
            r = l;
            while (r < n && B[i][l] == B[i][r]) r++;
            g = gcd(g, r - l);
        }
        for (int l = 0, r; l < n; l = r) {
            r = l;
            while (r < n && B[l][i] == B[r][i]) r++;
            g = gcd(g, r - l);
        }
    }
    printf("%d\n", g);
    return 0;
}