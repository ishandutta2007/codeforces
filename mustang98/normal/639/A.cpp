#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    if (a<b) swap(a,b);
    while (b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}
map <ll, ll> s;

int main()
{
    map <ll,ll>::iterator it;
    ll n, q, k,a, num;
    ll f[200001];
    //cin>>a>>b;
    cin>>n>>k>>q;
    for (int i=0;i<n;i++)
    {
        cin>>f[i];
        //m[f[i]]=i;
    }
    for (int i=0;i<q;i++)
    {
        cin>>a>>num;
        num--;
        if (a==1)
        {
            if (s.size()<k) s[f[num]]=num;
            else
            {
                if (s.begin()->first > f[num]) continue;
                else
                {
                    s.erase(s.begin());
                    s[f[num]]=num;
                }
            }
        }
        else if (s.count(f[num])) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}