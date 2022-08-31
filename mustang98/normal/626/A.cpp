#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <string>

using namespace std;
typedef long long ll;

using namespace std;

ll gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    while (b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}

int main()
{
    ll ku=0,kd=0,kl=0,kr=0,n,a,b, res=0;
    ll m[1000];
    cin>>n;
    string s;
    cin>>s;
    for (int i=0;i<n;i++)
    {
        kl=kr=kd=ku=0;
        for (int j=i;j<n;j++)
        {
            if (s[j]=='U') ku++;
            if (s[j]=='D') kd++;
            if (s[j]=='L') kl++;
            if (s[j]=='R') kr++;
            if (ku==kd && kl==kr) res++;
        }
    }
    cout<<res;

    //for(int i=0;i<n;i++) cin>>m[i];
    return 0;
}