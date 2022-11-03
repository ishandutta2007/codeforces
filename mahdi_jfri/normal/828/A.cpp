#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int main()
{
    ll n , a , b;
    ll c = 0 , res = 0;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x == 1)
        {
            if(!a)
            {
                if(!b)
                {
                    if(!c)
                        res++;
                    else
                        c--;
                }
                else
                {
                    b--;
                    c++;
                }
            }
            else
                a--;
        }
        else
        {
            if(!b)
                res += 2;
            else
                b--;
        }
    }
    cout << res;
}