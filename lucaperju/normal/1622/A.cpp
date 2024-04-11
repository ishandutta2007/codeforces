#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long q,h,k,s=0,t,i,j,m;
    cin>>t;
    while(t--)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        if(c>b)
        swap(c,b);
        if(b>a)
            swap(a,b);
        if(a==b+c || a%2==0 && b==c)
        cout<<"YES\n";
        else
        {
       //     cout<<"NO\n";
            if(b<c)
                swap(b,c);
            if(a==b && c%2==0)
            {
                cout<<"YES\n";
            }
            else
                cout<<"NO\n";
        }
    }
}