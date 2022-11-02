#include <bits/stdc++.h>

using namespace std;

const int INF = 1000 * 1000 * 1000;
const int N = 5555;

int f[N][N];
int a[N];
int n;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            f[i][j] = a[j] > i ? 1 : 0;
            if (j)
                f[i][j] += f[i][j - 1];
        }
    /*for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int s = 0;
            for (int k = 0; k <= j; k++)
                if (a[k] > i)
                    s++;
            assert(s == f[i][j]);
        }*/
    int best = INF;
    int cnt = 0;
    int x, y;
    for (int l = 0; l < n; l++)
        for (int r = l + 1; r < n; r++)
        {
            int vl = a[l];
            int vr = a[r];
            int bigL = f[vl][r] - f[vl][l];
            int smallL = r - l - bigL;
            int bigR = f[vr][r] - f[vr][l];
            int smallR = r - l - bigR;
            int cur = 0;
            cur -= smallL;
            cur += bigL;
            cur += smallR;
            cur -= bigR;
            if (vl > vr)
                cur--;
            if (cur < best)
            {
                best = cur;
                x = l;
                y = r;
                cnt = 1;
            }
            else if (cur == best)
            {
                cnt++;
            }
        }

    swap(a[x], a[y]);
    int tot = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[j] > a[i])
                tot++;

    cout << tot << " " << cnt;

    return 0;
}