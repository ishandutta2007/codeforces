#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e6 + 20;
ll a[maxn] , res;
int main()
{
    int n , x;
    cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        a[k]++;
    }
    for(int i = 0; i < maxn; i++)
    {
        if(a[i])
        {
            if((i ^ x) == i)
            {
                res += a[i] * (a[i] - 1);
            }
            else
                res += a[i ^ x] * a[i];
        }
    }
    cout << res / 2;
}