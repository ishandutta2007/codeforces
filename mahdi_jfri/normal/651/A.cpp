#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int c=min(a,b);
    int d=max(a,b),t=0;
    if(c+d==2)
    {
        cout<<"0";
        return 0;
    }
    while(c>0)
    {
        c++;
        d-=2;
        t++;
        if(c>d)
        {
            int x=d;
            d=c;
            c=x;
        }
    }
    cout<<t;
}