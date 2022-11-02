#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int m,n,i,j,ans=0;
        cin>>n>>m;
        int a[n][m];
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                cin>>a[i][j];
        int top = n+m-2, bot = 0;
        int tol[n+m+5];
        for(i=0;i<n+m+2;i++)
            tol[i] = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                tol[i+j]+=a[i][j];
            }
        }
        int mini = min(n,m);
        for(i=0;i<=(n+m-3)/2;i++)
        {
            ans+=min(tol[i]+tol[n+m-2-i],min(i+1,mini)*2 - tol[i] - tol[n+m-2-i]);
        }
        cout<<ans<<"\n";
    }
}