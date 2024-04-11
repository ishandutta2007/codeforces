#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int cur=1;
        while(b>1)
        {
            a-=cur;
            --b;
            cur+=2;
            if(a<0)
                break;
        }
        if(a>0 && a%2 && a>=cur)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}