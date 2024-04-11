#include <bits/stdc++.h>

using namespace std;
int v[250005],lg[250005],mn[250005],mx[250005];
int main()
{
    ios_base::sync_with_stdio(false);
    int k=0,t,i,j,n,m,x,y,ok=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        mn[n]=mx[n]=n;
        for(i=n-1;i>=1;--i)
        {
            if(v[i]<v[mn[i+1]])
                mn[i]=i;
            else
                mn[i]=mn[i+1];
            if(v[i]>v[mx[i+1]])
                mx[i]=i;
            else
                mx[i]=mx[i+1];
        }
        int cnt=0;
        i=1;
        int from=i+1;
        while(i<n)
        {
            ++cnt;
            if(v[i+1]>v[i])
            {
                if(from==n+1)
                {
                    i=mx[i];
                    continue;
                }
                int pz=from;
                for(j=from;j<=n && v[j]>v[i];++j)
                {
                    if(v[j]>v[pz])
                        pz=j;
                }
                from=j;
                i=pz;
            }
            else
            {
                if(from==n+1)
                {
                    i=mn[i];
                    continue;
                }
                int pz=from;
                for(j=from;j<=n && v[j]<v[i];++j)
                {
                    if(v[j]<v[pz])
                        pz=j;
                }
                from=j;
                i=pz;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}