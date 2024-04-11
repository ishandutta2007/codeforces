#include <bits/stdc++.h>

using namespace std;
int v[1003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long m,n,i,t,j,k,mx,p,mxx=0;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int pz=1;
        if(a)
        {
            for(i=1;i<=a+1;++i)
                v[i]=0;
            pz=i;
        }
        if(c)
        {
            for(i=pz;i<=pz+c;++i)
                v[i]=1;
            pz=i;
        }
        for(i=pz;i<=a+b+c+1;++i)
        {
            v[i]=1-v[i-1];
        }
        for(i=1;i<=a+b+c+1;++i)
            cout<<v[i];
        cout<<'\n';
    }
    return 0;
}