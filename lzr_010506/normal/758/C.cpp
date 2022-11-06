#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;

ll a[101][101];
int main() 
{
    int n , m , x , y;
    ll k;
    cin >> n >> m >> k >> x >> y;
    vector< pair<int , int> > V;
    if (n == 1) 
    {
        for (int i = 0 ; i < m ; i ++) 
            V.push_back({1 , i + 1});
    } 
    else 
    {
        for (int i = 1 ; i < n ; i ++) 
            for (int j = 1 ; j <= m ; j ++) 
                V.push_back({i , j});
        for (int i = 1 ; i < n ; i ++) 
            for (int j = 1 ; j <= m ; j ++) 
                V.push_back({n - i + 1 , j});
    }
    int T = V.size();
    ll P = k / T , mn = 1LL << 60 , mx = 0;
    for (auto it : V) 
        a[it.X][it.Y] += P;
    
    k %= T;
    for (auto it : V) 
    {
        if (!k) break; 
        -- k;
        a[it.X][it.Y] ++;
    }
    for (int i = 1 ; i <= n ; i ++) 
        for (int j = 1 ; j <= m ; j ++) 
        {
            mn = min(mn , a[i][j]);
            mx = max(mx , a[i][j]);
        }
    
    cout << mx << ' ' << mn << ' ' << a[x][y] << endl;
    return 0;
}