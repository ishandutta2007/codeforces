#include<bits/stdc++.h>
using namespace std;
long long t,x,y,a,b;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>a>>b;
        if(b>2*a)
        {
            cout<<a*(x+y)<<"\n";
        }
        else
        {
            cout<<a*(abs(x-y))+b*min(x,y)<<"\n";   
        }
    }
    return 0;
}