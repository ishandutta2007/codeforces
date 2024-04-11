#include <bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,i,j,k;
    cin>>t;
    while(t--)
    {
        long long n,a,b,x,y;
        cin>>a>>b>>x>>y>>n;
        if(max(a-n,x)>max(b-n,y))
        {
            swap(a,b);
            swap(x,y);
        }
            if(a-x<=n)
            {
                n-=(a-x);
                a=x;
            }
            else
            {
                a-=n;
                n=0;
            }
            if(b-y<=n)
            {
                n-=(b-y);
                b=y;
            }
            else
            {
                b-=n;
                n=0;
            }
        cout<<a*1LL*b<<'\n';
    }
}