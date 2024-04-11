#include <iostream>
#include <cstdio>
using namespace std;

const int N = 505, DX[5] = {1, -1, 1, -1, 0}, DY[5] = {1, -1, -1, 1, 0};

int n, ans = 0;
char s[N][N];

int main()
{
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
        scanf("%s", s[i] + 1);
    for (int i = 2; i < n; i++)
        for (int j = 2; j < n; j++)
        {
            ans++;
            for (int k = 0; k < 5; k++)
                if (s[i + DX[k]][j + DY[k]] == '.')
                {
                    ans--;
                    break;
                }
        }
    printf("%d", ans);
}