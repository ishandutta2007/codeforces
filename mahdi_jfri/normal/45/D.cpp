#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll l[maxn] , r[maxn] , is[maxn * 100] , res[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
        ll k = i;
        while(is[l[k]])
        {
            if(r[k] >= r[is[l[k]]])
            {
                l[k]++;
            }
            else
            {
                res[k] = l[k];
                swap(k , is[l[k]]);
            }
        }
        is[l[k]] = k;
        res[k] = l[k];
    }
    for(int i = 1; i <= n; i++)
        cout << res[i] << " ";
}