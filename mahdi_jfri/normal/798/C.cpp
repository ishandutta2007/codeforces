#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll a[maxn] , res , gcd;
bool f;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        gcd = __gcd(a[i] , gcd);
    }
    cout << "YES\n";
    if(gcd > 1)
    {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        if(a[i] % 2)
        {
            if(a[i + 1] % 2)
            {
                res++;
                a[i + 1] = 2;
                a[i] = 2;
            }
            else
            {
                if(i && a[i - 1] % 2)
                {
                    res++;
                    a[i - 1] = a[i] = 2;
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(a[i] % 2)
        {
            res += 2;
        }
    }
    cout << res;
}