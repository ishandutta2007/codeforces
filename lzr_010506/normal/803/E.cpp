#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
const int N = 1005;

int n, k;
char s[N];
pair<bool, char> f[N][N * 2];
char ans[N] = { 0 };

int main()
{
    scanf("%d%d", &n, &k); getchar();
    for (int i = 0; i < n; i ++) s[i] = getchar();

    for (int i = 0; i < N; i ++)
        for (int j = 0; j < N * 2; j ++) 
        	f[i][j] = make_pair(false, -1);

    f[0][N] = make_pair(true, 0);
    for (int i = 0; i < n; i ++) 
        for (int j = 0; j < N * 2; j ++) if (f[i][j].X) 
        {
            if ((s[i] == 'W' || s[i] == '?') && j + 1 < N + k + (i == n - 1))
                f[i + 1][j + 1] = make_pair(true, 'W');
            if ((s[i] == 'L' || s[i] == '?') && j - 1 > N - k - (i == n - 1))
                f[i + 1][j - 1] = make_pair(true, 'L');
            if (s[i] == 'D' || s[i] == '?')
                f[i + 1][j] = make_pair(true, 'D');
        }

    int st = -1;
    if (f[n][N + k].X) st = N + k;
    else if (f[n][N - k].X) st = N - k;
    else { puts("NO"); return 0; }

    for (int i = n; i > 0; i --) 
    {
        ans[i - 1] = f[i][st].Y;
        switch (f[i][st].Y) 
        {
            case 'W': st --; break;
            case 'L': st ++; break;
            case 'D': default: break;
        }
    }
    puts(ans);

    return 0;
}