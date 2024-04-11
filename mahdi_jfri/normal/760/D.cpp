#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int a[maxn];
ll res[maxn];
int main()
{
    int n , x , y;
    x = y = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        while (a[i] - a[x] > 89)
            x++;
        if(x > 0)
            x--;
        while (a[i] - a[y] > 1439)
            y++;
        if(y > 0)
            y--;
        res[i] = min(res[i - 1] + 20 , min(res[x] + 50 , res[y] + 120));
        cout << res[i] - res[i - 1] << endl;
    }
}