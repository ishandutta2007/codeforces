#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (a & (1 << b))
const int maxn = 1e2 + 20;
ll n , m , k , x , y , sum , all , _max , _min = 9e18, s , a[maxn][maxn];
void d(int i , bool z)
{
    if(!k)
        return;
    for(int j = 0; j < m && k; j++)
        a[i][j]++ , k--;
    if(z && i != n - 1)
        d(i + 1 , z);
    else if(z && i == n - 1)
        d(i - 1 , !z);
    if(!z && i != 0)
        d(i - 1 , z);
    else if(!z)
        d(i + 1 , !z);
    return;
}
int main()
{
    cin >> n >> m >> k >> x >> y;
    sum = n * m * 2 - 2 * m;
    if(n == 1)
    {
        sum = k / m;
        k %= m;
        if(k)
            cout << sum + 1 << " ";
        else
            cout << sum << " ";
        cout << sum << " ";
        if(y <= k)
            cout << sum + 1;
        else
            cout << sum;
        return 0;
    }
    all = k / sum;
    k -= all * sum;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(!i || i == n - 1)
                a[i][j] = all;
            else
                a[i][j] = 2 * all;
        }
    d(0 , 1);
    x-- , y--;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            _max = max(_max , a[i][j]) , _min = min(_min , a[i][j]);
    cout << _max << " " << _min << " " << a[x][y];
}