#include <bits/stdc++.h>
using namespace std;
long long v[100005];
int main()
{
    long long n,m,i,j,x,y,k,t,l,r;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long s=0;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            s^=v[i];
        }
        if(s==0)
        {
            cout<<"DRAW\n";
            continue;
        }
        while(s&(s-1))
            s=(s&(s-1));
        int cnt=0;
        for(i=1;i<=n;++i)
            if(v[i]&s)
                ++cnt;
        int cnt0=n-cnt;
        if((cnt/2)%2==cnt0%2 || (cnt/2)%2==0)
            cout<<"WIN\n";
        else
            cout<<"LOSE\n";
    }
    return 0;
}