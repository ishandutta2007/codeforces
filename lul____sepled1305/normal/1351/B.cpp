#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,d;
 
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        bool suc = false;
        if(a==c && !suc)
        {
            if(b+d==c)
                suc = true;
            else
                suc = false;
        }
        if (a==d && !suc)
        {
            if(b+c==d)
                suc = true;
            else
                suc = false;
        }
        if (b==c && !suc)
        {
            if(a+d==c)
                suc = true;
            else
                suc = false;
        }
        if (b==d && !suc)
        {
            if(a+c==d)
                suc = true;
            else
                suc = false;
        }
        if(suc)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}