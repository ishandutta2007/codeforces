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
    int n,kr=0,kg=0,kb=0;
    cin>>n;
    string s;
    cin>>s;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='R') kr++;
        if (s[i]=='G') kg++;
        if (s[i]=='B') kb++;
    }
    if (kr && kg && kb)
    {
        cout<<"BGR";
        return 0;
    }
    if (kr>1 && kg>1 || kr>1 && kb>1 || kb>1 && kg>1)
    {
        cout<<"BGR";
        return 0;
    }

    ll sum=kr+kb+kg;
    if (kr && !kg && !kb)
    {
        cout<<"R";
        return 0;
    }

    if (kg && !kr && !kb)
    {
        cout<<"G";
        return 0;
    }

    if (kb && !kg && !kr)
    {
        cout<<"B";
        return 0;
    }

    if (sum==2)
    {
        if (kr==1 && kg==1)
        {
            cout<<"B";
            return 0;
        }

        if (kr==1 && kb==1)
        {
            cout<<"G";
            return 0;
        }

        if (kb==1 && kg==1)
        {
            cout<<"R";
            return 0;
        }
    }
    //1 and absent
    if(kr==1)
    {
        if (kb) {cout<<"GR"; return 0;}
        if (kg) {cout<<"BR"; return 0;}
    }

    if(kb==1)
    {
        if (kr) {cout<<"BG"; return 0;}
        if (kg) {cout<<"BR"; return 0;}
    }

    if(kg==1)
    {
        if (kb) {cout<<"GR"; return 0;}
        if (kr) {cout<<"BG"; return 0;}
    }
    return 0;
}