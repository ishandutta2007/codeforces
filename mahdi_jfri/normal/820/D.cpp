#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e6 + 20;
int a[maxn] , n;
ll res[maxn] , ziad[maxn] , kam[maxn] , _min = 1e18 , node , x[maxn] , k[maxn];
vector<int> payan[maxn] , an[maxn];
void add1(ll l , ll r , ll k)
{
    if(l > r)
        return;
    x[l] += k;
    x[r + 1] -= k;
    ziad[l + 1]++;
    ziad[r + 1]--;
    res[r + 1] -= r - l;
}
void add2(ll l , ll r , ll k)
{
    if(l > r)
        return;
    x[l] += k;
    x[r + 1] -= k;
    kam[l + 1]++;
    kam[r + 1]--;
    an[r + 1].pb(l);
    res[r + 1] += r - l;
}
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++)
    {
        if(a[i] >= i)
        {
            add2(0 , a[i] - i , a[i] - i);
            add1(a[i] - i , n - i , 0);
            add2(n - i + 1 , n - 1 , a[i] - 1);
        }
        else
        {
            add1(0 , n - i , i - a[i]);
            add2(n - i + 1 , n - i + a[i] , a[i] - 1);
            add1(n - i + a[i] , n - 1 , 0);
        }
    }
    for(int i = 1; i < n; i++)
        x[i] += x[i - 1] , ziad[i] += ziad[i - 1] , kam[i] += kam[i - 1];
    for(int i = 0; i < n; i++)
    {
        res[i] += x[i] + ziad[i] + k[i - 1] - kam[i];
        k[i] = res[i] - x[i];
        if(res[i] < _min)
        {
            node = i;
            _min = res[i];
        }
    }
    cout << _min << " " << node << endl;
}