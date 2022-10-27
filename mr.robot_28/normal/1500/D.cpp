#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n][n];
    bool used[n * n + 1];
    fill(used, used + n * n + 1, 0);
    pair <int, int> close[n][n][k + 1];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    vector <int> pref(n + 3, 0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            vector <pair <int, int>> arr;
            arr.push_back({1, a[i][j]});
            if(i >= 1)
            {
                for(int e = 0; e <= k; e++)
                {
                    if(close[i - 1][j][e] == make_pair(0, 0))
                    {
                        break;
                    }
                    arr.push_back(close[i -1][j][e]);
                    arr.back().X++;
                }
            }
            if(j >= 1)
            {
                for(int e = 0; e <= k; e++)
                {
                    if(close[i][j - 1][e] == make_pair(0, 0))
                    {
                        break;
                    }
                    arr.push_back(close[i][j - 1][e]);
                    arr.back().X++;
                }
            }
            if(i >= 1 && j >= 1)
            {
                for(int e = 0; e <= k; e++)
                {
                    if(close[i - 1][j - 1][e] == make_pair(0, 0))
                    {
                        break;
                    }
                    arr.push_back(close[i - 1][j - 1][e]);
                    arr.back().X++;
                }
            }
            sort(arr.begin(), arr.end());
            int t  = 0;
            for(auto p : arr)
            {
                if(used[p.Y])
                {
                    continue;
                }
                used[p.Y] = 1;
                close[i][j][t++] = p;
                if(t > k)
                {
                    break;
                }
            }
            for(auto p : arr)
            {
                used[p.Y] = 0;
            }
            int can = min(i, j) + 1;
            if(close[i][j][k] != make_pair(0, 0))
            {
                 can = min(can, close[i][j][k].X - 1);
            }
            pref[1]++;
            pref[can + 1]--;
        }
    }
    int bal = 0;
    for(int i= 1; i <= n; i++)
    {
        bal += pref[i];
        cout << bal << "\n";
    }
    return 0;
}