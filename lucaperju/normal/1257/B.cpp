#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n,x,a,b;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if(x>=4)
            cout<<"YES\n";
        if(x==3 || x==2)
        {
            if(y<=3)
            cout<<"YES\n";
                else
                    cout<<"NO\n";
        }
        if(x==1)
        {
            if(y==1)
            {
                cout<<"YES\n";
            }
            else
                cout<<"NO\n";
        }
    }
    return 0;
}