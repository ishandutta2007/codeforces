#include <bits/stdc++.h>
using namespace std;
char v[103];
long long xp[300005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,j,m,q,n,s=0;
    cin>>t;
    for(i=1;i<=300000;++i)
    {
        xp[i]=(i^xp[i-1]);
    }
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        long long s=0;
        s=xp[a-1];
        if(s==b)
        {
            cout<<a<<'\n';
        }
        else if((s^b)==a)
        {
            cout<<a+2<<'\n';
        }
        else
        {
            cout<<a+1<<'\n';
        }
    }
    return 0;
}