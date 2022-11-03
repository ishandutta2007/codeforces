#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e6 + 20;
bool is[maxn];
int now = 1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n , m , k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        is[x] = 1;
    }
    if(is[1])
    {
         cout << 1;
         return 0;
    }
    for(int i = 0; i < k; i++)
    {
        int v , u;
        cin >> v >> u;
        if(v == now)
        {
            swap(now , u);
        }
        else if(u == now)
        {
            swap(now , v);
        }
        if(is[now])
        {
            cout << now;
            return 0;
        }
    }
    cout << now;
}