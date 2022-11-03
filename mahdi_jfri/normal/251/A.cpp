#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define int ll
const int maxn = 1e5 + 20;
int a[maxn] , d , x , res;
int bs(int l, int r)
{
    if(r == l)
        return l;
    if(r - l == 1)
    {
        if(abs(x - a[l]) <= d)
            return l;
        if(abs(x - a[r]) <= d)
           return r;
        return -1;
    }
    if(abs(x - a[r]) > d)
        return -1;
    int mid = (r - l) / 2 + l;
    if(abs(x - a[mid]) == d)
        return mid;
    if(abs(x - a[mid]) > d)
        return bs(mid , r);
    else
        return bs(l , mid);
}
main()
{
    int n;
    cin >> n >> d;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 2; i < n; i++)
    {
        x = a[i];
        ll k = bs(0 , i - 1);
        if(k == -1)
            continue;
        k = i - k;
        res += (k * (k - 1)) / 2;
    }
    cout << res;
}