#include <bits/stdc++.h>

using namespace std;

const int max_n = 1005;

int m[max_n][max_n];
int kr[max_n], kcol[max_n];

int main()
{
    int n,M;
    cin >> n >> M;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf("%d", &m[i][j]);
            if (m[i][j] == 1)
            {
                kr[i]++;
                kcol[j]++;
            }
        }
    }

    int ans = 0;
    int r, l;

    for(int i = 0; i < n; i++)
    {
        r = kr[i];
        for(int j = 0; j < M; j++)
        {
            if (m[i][j] == 1) r--;
            else
            {
                l = kr[i] - r;
                if (r) ans++;
                if (l) ans++;
            }
        }
    }

    for(int i = 0; i < M; i++)
    {
        r = kcol[i];
        for(int j = 0; j < n; j++)
        {
            if (m[j][i] == 1) r--;
            else
            {
                l = kcol[i] - r;
                if (r) ans++;
                if (l) ans++;
            }
        }
    }
    cout << ans;

}