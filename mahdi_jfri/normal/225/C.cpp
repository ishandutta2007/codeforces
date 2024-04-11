#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 20;
const int inf = 1e9;
string s;
int dpn[maxn];
int dps[maxn];
int sum[maxn];
int summ[maxn];
int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        for(int j = 1; j <= m; j++)
        {
            if(s[j - 1] == '.')
                sum[j]++;
        }
    }
    for(int i = 1; i <= m; i++)
        summ[i] = summ[i - 1] + sum[i];
    for(int i = 1; i <= m; i++)
        dps[i] = dpn[i] = inf;
    for(int i = x; i <= m; i++)
    {
        for(int j = i - x + 1; j > i - y && j > 0; j--)
        {
            dps[i] = min(summ[i] - summ[j - 1] + dpn[j - 1] , dps[i]);
            dpn[i] = min(n * (i - j + 1) - (summ[i] - summ[j - 1]) + dps[j - 1] , dpn[i]);
        }
    }
    cout << min(dps[m] , dpn[m]);
}