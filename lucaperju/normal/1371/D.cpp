#include <bits/stdc++.h>
using namespace std;
int v[303][303];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long i,j,n,t,m,k,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                v[i][j]=0;
        j=1;
        for(int kk=1;kk<=n;++kk)
        {
            if(k==0)
                break;
            j=kk;
            for(int i=1;i<=n;++i)
            {
                v[i][j]=1;
                ++j;
                --k;
                if(j==n+1)
                    j=1;
                if(k==0)
                    break;
            }
            if(k==0)
                break;
        }
        int s=0;
        for(i=1;i<=n;++i)
            s+=v[1][i];
        for(i=1;i<=n;++i)
            s-=v[n][i];
        cout<<s*s*2<<'\n';
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
                cout<<v[i][j];
            cout<<'\n';
        }
    }
    return 0;
}