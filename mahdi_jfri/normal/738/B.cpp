#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e3 + 20;
bool mp[maxn][maxn];
bool has[maxn] , hasc[maxn];
int t , res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
            if(mp[i][j])
                has[i] = 1 , hasc[j] = 1;
        }
    for(int i = 0; i < n; i++)
    {
        t = 0;
        for(int j = 0; j < m; j++)
        {
            if(mp[i][j])
                res += t , t = 0;
            else
                t++;
        }
        t = 0;
        for(int j = m - 1; j > -1; j--)
        {
            if(mp[i][j])
                res += t , t = 0;
            else
                t++;
        }
    }
    for(int j = 0; j < m; j++)
    {
        t = 0;
        for(int i = 0; i < n; i++)
        {
            if(mp[i][j])
                res += t , t = 0;
            else
                t++;
        }
        t = 0;
        for(int i = n - 1; i > -1; i--)
        {
            if(mp[i][j])
                res += t , t = 0;
            else
                t++;
        }
    }
    cout << res;
}