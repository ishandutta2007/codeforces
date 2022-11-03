#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 20;
int a[maxn] , _max = 1;
map<int , int> mp;
ll x[60] , res;
int main()
{
    x[0] = 2;
    int i = 1;
    while(x[i - 1] < 1e9)
        x[i] = x[i - 1] * 2 , i++;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i] , mp[a[i]]++;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 30; j++)
        {
            if(a[i] >= x[j])
                continue;
            if(x[j] - a[i] == a[i])
            {
                if(mp[a[i]] > 1)
                    res += mp[a[i]] - 1;
                continue;
            }
            if(mp[x[j] - a[i]])
                res += mp[x[j] - a[i]];
        }
    }
    cout << res / 2;
}