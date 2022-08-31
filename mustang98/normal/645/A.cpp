#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <cctype>
#include <cstring>
#include <string>

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
    ll n, a, b;
    ll m[10000];
    //cin>>n;
    string s1[2];
    string s2[2];
    cin>>s1[0]>>s1[1]>>s2[0]>>s2[1];
    vector <char> v1; vector <char>v2;
    vector <char> r1,r2;
    bool fl1=false, fl2=false;
    if (s1[0][0]!='X') v1.push_back(s1[0][0]);
    if (s1[0][1]!='X') v1.push_back(s1[0][1]);
    if (s1[1][1]!='X') v1.push_back(s1[1][1]);
    if (s1[1][0]!='X') v1.push_back(s1[1][0]);


    if (s2[0][0]!='X') v2.push_back(s2[0][0]);
    if (s2[0][1]!='X') v2.push_back(s2[0][1]);
    if (s2[1][1]!='X') v2.push_back(s2[1][1]);
    if (s2[1][0]!='X') v2.push_back(s2[1][0]);
    for (int i=0;i<3;i++)
    {
        if (v1[i]=='A') fl1=true;
        if (fl1) r1.push_back(v1[i]);
    }
    for (int i=0;i<3;i++)
    {
        if (v1[i]=='A') fl1=true;
        if (fl1) r1.push_back(v1[i]);
    }

    for (int i=0;i<3;i++)
    {
        if (v2[i]=='A') fl2=true;
        if (fl2) r2.push_back(v2[i]);
    }
    for (int i=0;i<3;i++)
    {
        if (v2[i]=='A') fl2=true;
        if (fl2) r2.push_back(v2[i]);
    }

    //for (int i=0;i<3;i++) cout<<r1[i];

    //for (int i=0;i<3;i++) cout<<r2[i];
    //for (int i=0;i<n;i++) cin>>m[i];
    if (r1[0]==r2[0] && r1[1]==r2[1] && r1[2]==r2[2]) {cout<<"YES";}
    else cout<<"NO";

    return 0;
}