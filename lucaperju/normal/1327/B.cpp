#include <bits/stdc++.h>
using namespace std;
int viz[100005],ok[100005];
int main()
{
    int t,i,j,n,m,cnt=0;
    cin>>t;
    while(t--)
    {
        int cnt=0;
        cin>>n;
        for(j=1;j<=n;++j)
        {
            cin>>m;
            for(i=1;i<=m;++i)
            {
                int a;
                cin>>a;
                if(!viz[a] && !ok[j])
                    viz[a]=ok[j]=1,++cnt;
            }
        }
        if(cnt==n)
        cout<<"OPTIMAL\n";
        else
        {
            cout<<"IMPROVE\n";
            for(i=1;i<=n;++i)
                if(ok[i]==0)
                    break;
            cout<<i<<' ';
            for(i=1;i<=n;++i)
                if(viz[i]==0)
                    break;
            cout<<i<<'\n';
        }
        for(i=1;i<=n;++i)
            ok[i]=viz[i]=0;
    }
    return 0;
}