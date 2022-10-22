#include <cstdio>
using namespace std;

const int Maxn = 2005;

int n;
char B[Maxn][Maxn];
bool row[Maxn], col[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf(" %c", &B[i][j]);
    for (int i = n - 1; i >= 0; i--) {
        bool inv = false;
        for (int j = 0; j < i; j++)
            if (inv ^ row[j] ^ B[j][i] == '1') {
                    res++; 
                    row[j] = !row[j];
                    inv = !inv;
            }
        bool inv2 = false;
        for (int j = 0; j < i; j++)
            if (inv2 ^ col[j] ^ B[i][j] == '1') {
                    res++;
                    col[j] = !col[j];
                    inv2 = !inv2;
            }
        if (inv ^ inv2 ^ row[i] ^ col[i] ^ B[i][i] == '1') res++;
    }
    printf("%d\n", res);
    return 0;
}