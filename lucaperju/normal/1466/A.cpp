#include <bits/stdc++.h>
using namespace std;
int fv[1003];
int v[103];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,k,mod,m;
    long long x1,y1,x2,y2;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
        }
        for(i=1;i<=50;++i)
            fv[i]=0;
        int cnt=0;
        for(i=1;i<=n;++i)
            for(j=i+1;j<=n;++j)
            {
                if(fv[v[j]-v[i]]==0)
                    ++cnt;
                fv[v[j]-v[i]]=1;
            }
        cout<<cnt<<'\n';
    }
    return 0;
}