#include <bits/stdc++.h>

using namespace std;
int v[55];
int main()
{
    ios_base::sync_with_stdio(false);
    int k=0,r,t,i,j,n,a,b,m,x,y,ok=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        if(n%2)
        {
            cout<<"Mike\n";
            continue;
        }
        long long s=0;
        for(i=3;i<=n;++i)
        {
            v[i]=min(v[i],v[i-2]);
        }
        for(i=1;i<=n;i+=2)
        {
            v[i]=min(v[i],v[n-1]+1);
        }
        for(i=2;i<=n;i+=2)
            v[i]=min(v[i],v[n]+1);
        for(i=1;i<=n;++i)
        {
            if(i%2==1)
                s+=v[i];
            else
                s-=v[i];
        }
        if(s>0)
            cout<<"Mike\n";
        else
            cout<<"Joe\n";
    }
    return 0;
}