#include <bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a0,a1,a2,b0,b1,b2;
        cin>>a0>>a1>>a2>>b0>>b1>>b2;
        int sumc=min(a2,b1);
        a2-=sumc;
        b1-=sumc;
        sumc<<=1;
        sumc-=max(0,b2-(a2+a0))*2;
        cout<<sumc<<'\n';
    }
}