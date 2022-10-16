#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m,i,j,x,y,k,t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int mx=a;
        mx=max(mx,b);
        mx=max(mx,c);
        int cnt=0;
        if(mx==a)
            ++cnt;
        if(mx==b)
            ++cnt;
        if(mx==c)
            ++cnt;
        if(cnt==3)
        {
            cout<<"YES\n";
            cout<<a<<' '<<a<<' '<<a<<'\n';
        }
        else if(cnt==1)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
            if(a!=mx)
            {
                cout<<1<<' '<<a<<' '<<mx;
            }
            else if(b!=mx)
            {
                cout<<1<<' '<<mx<<' '<<b;
            }
            else if(c!=mx)
            {
                cout<<mx<<' '<<1<<' '<<c;
            }
            cout<<'\n';
        }
    }
    return 0;
}