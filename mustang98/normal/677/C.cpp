#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

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

int bit[65][65];

int main()
{
    ll a, b, n, h;
    ll kol[100]={0};
    ll m[10000]={0};
    for (int i = 0; i < 64;i++)
        for (int j =0;j<64;j++)
        {bit[i][j] = i&j; kol[i&j]++;}
    /*for (int i=0;i<64;i++)
    {
        for(int j=0;j<64;j++) cout<<bit[i][j]<<' ';
        cout<<endl;
    }*/
    //cout<<kol[31]<<endl;
    string s;
    cin>>s;
    int S[100009];
    for (int i =0;i<s.length();i++)
    {
        if (s[i]=='-') S[i]=62;
        else if (s[i] =='_') S[i]=63;
        else if (s[i]>='0' && s[i]<='9')
            S[i]=s[i]-'0';
        else if (s[i]>='A' && s[i]<='Z')
            S[i]=s[i]-'A'+10;
        else S[i]=s[i]-'a'+36;
    }
    //cout<<S[1]<<endl;
    //for (int i =0;i<100;i++) cout<<kol[i]<<' ';
    ll ans=1;
    for (int i=0;i<s.length();i++)
    {
        ans*=kol[S[i]];
        ans%=1000000007;
    }
    cout<<ans;
    return 0;
}