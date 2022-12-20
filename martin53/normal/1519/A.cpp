#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t)
    {
        t--;

        int r,b,d;

        cin>>r>>b>>d;

        if(r<b)swap(r,b);

        if(1LL*b*(d+1)>=r)cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}