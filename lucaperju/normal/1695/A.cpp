#include <bits/stdc++.h>

using namespace std;
int v[55][55];
int main()
{
    ios_base::sync_with_stdio(false);
    int k=0,r,t,i,j,n,a,b,m,x,y,ok=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int a=1,b=1;
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
            {
                cin>>v[i][j];
                if(v[i][j]>v[a][b])
                {
                    a=i;
                    b=j;
                }
            }
        }
        cout<<max(a,n-a+1)*max(b,m-b+1)<<'\n';
    }
    return 0;
}