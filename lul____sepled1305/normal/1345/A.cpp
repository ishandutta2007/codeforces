#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(min(a,b)==1)
        {
            cout<<"YES\n";
        }
        else if(a==b && a==2)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}