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

int main()
{
    ll n,a,b;
    cin>>n>>a>>b;
    for (int i=0;i<abs(b);i++)
    {
        if (b==0) break;
        if (b<0) {a--;}
        else {a++;};
        if (a==n+1) a=1;
        if (a==0) a=n;
    }
    cout<<a;
    return 0;
}