#include <bits/stdc++.h>
using namespace std;
int v[100005],fv[200005];
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
            fv[i]=fv[i+n]=0;
        }
        fv[n+n+1]=0;
        int cnt=0;
        for(i=1;i<=n;++i)
        {
            if(fv[v[i]]==0)
            {
                fv[v[i]]=1;
                ++cnt;
            }
            else if(fv[v[i]+1]==0)
            {
                fv[v[i]+1]=1;
                ++cnt;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}