#include <bits/stdc++.h>
using namespace std;

const int Maxd = 10;
const int Maxn = 2000005;
const int Inf = 1000000000;

int my[Maxd][Maxd][Maxd];
char str[Maxn];
int slen;
int res[Maxd][Maxd];

int Get(int a, int b)
{
    int res = 0;
    for (int i = 0; i + 1 < slen; i++) {
        int fir = str[i] - '0';
        int sec = str[i + 1] - '0';
        int got = (sec - fir + Maxd) % Maxd;
        if (my[a][b][got] >= Inf) return -1;
        res += my[a][b][got];
    }
    return res;
}

int main()
{
    for (int i = 0; i < Maxd; i++)
        for (int j = i; j < Maxd; j++) {
            fill(my[i][j], my[i][j] + Maxd, Inf);
            for (int a = 0; a < 10; a++)
                for (int b = 0; b < 10; b++) if (a || b) {
                    int s = (a * i + b * j) % 10;
                    my[i][j][s] = min(my[i][j][s], a + b - 1);
                }
        }
    scanf("%s", str);
    slen = strlen(str);
    for (int i = 0; i < Maxd; i++)
        for (int j = i; j < Maxd; j++)
            res[i][j] = res[j][i] = Get(i, j);
    for (int i = 0; i < Maxd; i++)
        for (int j = 0; j < Maxd; j++)
            printf("%d%c", res[i][j], j + 1 < Maxd? ' ': '\n');
    return 0;
}