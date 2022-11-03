#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll a[maxn];
int main()
{
    ll n , m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    for(int i = 0; i < m; i++)
    {
        ll l , r , x;
        scanf("%I64d%I64d%I64d", &l, &r ,&x);
        l--;
        r--;
        x--;
        ll t = 0 , t1 = 0;
        for(int i = l; i <= r && (t <= x - l || t1 <= r - x); i++)
        {
            if(a[i] < a[x])
                t++;
            else if(a[i] > a[x])
                t1++;
        }
        if(t == x - l)
            printf("Yes\n");
        else
            printf("No\n");
    }
}