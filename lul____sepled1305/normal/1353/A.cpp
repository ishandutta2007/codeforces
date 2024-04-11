#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(a==1)
            cout<<0<<"\n";
        else if(a==2)
            cout<<b<<"\n";
        else
            cout<<2*b<<"\n";
    }
    return 0;
}