#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n,m,k,i,j,z,ans,a[30];
bool f[60002];
char c;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        memset(a,0,sizeof(a));
        ans=~0u>>1;
        for(i=1;i<=k;i++)
        {
            cin>>c;
            a[c-'A']++;
        }
        for(i=0;i<26;i++) a[i]=min(a[i],n+m);
        k=0;
        for(i=0;i<26;i++) k+=a[i];
        for(i=0;i<26;i++)
        {
            if(a[i]==0) continue;
            memset(f,0,sizeof(f));
            f[0]=1;
            for(j=0;j<26;j++)
            {
                if(i==j) continue;
                for(z=n+m;z>=a[j];z--)
                   f[z]|=f[z-a[j]];
            }
            for(j=0;j<=n+m;j++)
               if(f[j])
               {
                  if(j<n-a[i]) continue;
                  if(k-j<m) break;
                  ans=min(ans,max(0,n-j)*max(0,m-(k-j-a[i])));
                  if(j>=n) break;
               }
        }
        cout<<ans<<"\n";
    }
    return 0;
}