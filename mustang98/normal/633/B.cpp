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
    int n,k5=0,t;
    cin>>n;
    for (int i=5;;i+=5)
    {
        t=i;
        while (t%5==0)
        {
            t/=5;
            k5++;
        }
        if (k5>n)
        {
            cout<<0;
            return 0;
        }
        if (k5==n)
        {
            cout<<5<<endl;
            cout<<i<<' '<<i+1<<' '<<i+2<<' '<<i+3<<' '<<i+4;
            return 0;
        }
    }
    return 0;
}