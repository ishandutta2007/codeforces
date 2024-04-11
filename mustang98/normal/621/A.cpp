#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    a=abs(a);
    b=abs(b);
    if(a<b) swap(a,b);
    while(b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}

vector <int> m;

int main()
{
    ll n, a, b, last,koln=0, minn=10e10;
    //ll m[1000];
    ll res=0;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a;
        res+=a;
        if (a%2)
        {
            koln++;
            minn = min(minn, a);
        }
    }
    if (koln%2) res-=minn;
    cout<<res;

    return 0;
}