#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <stack>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    a=abs(a);
    b=abs(b);
    if (a<b) swap(a,b);
    while (b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}

int main()
{
    ll a,b,c,n;
    ll m[1000];
    //cin>>n;
    //for (int i=0;i<n;i++) cin>>m[i];
    cin>>a>>b>>c;
    for (int x=0;x<=10000;x++)
    {
        if (a*x>c) break;
        if ((c-a*x)%b==0)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}