#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long n,i,j,m,mn=9999999,pz,a,b,s,x,y;
    char c;
    int h1,m1,h2,m2;
    cin>>c;
    h1=(c-'0')*10;
    cin>>c;
    h1+=c-'0';
    cin>>c;
    cin>>c;
    m1=(c-'0')*10;
    cin>>c;
    m1+=c-'0';
    ///-----
    cin>>c;
    h2=(c-'0')*10;
    cin>>c;
    h2+=c-'0';
    cin>>c;
    cin>>c;
    m2=(c-'0')*10;
    cin>>c;
    m2+=c-'0';
    x=h1*60+m1;
    y=h2*60+m2;
    a=(x+y)/2;
    int ca=a/60;
    if(ca<=9)
    {
        cout<<0<<ca<<':';
    }
    else
        cout<<ca<<':';
    ca=a%60;
    if(ca<=9)
    {
        cout<<0<<ca;
    }
    else
        cout<<ca;
    return 0;
}