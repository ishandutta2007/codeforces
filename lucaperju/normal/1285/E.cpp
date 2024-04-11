#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
map<int,int> newval;
int tot[400005];
int fv[400005];
int fvf[400005];
int ocp[400005];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,x,y,rz=0,n,root,m,w,i,j=0,k=0,pas=1<<15,sc=0,cnt=0,mn=0,nr1=0,nr2=0,mx=0,catc=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        j=0;
        cnt=0;
        for(i=1;i<=n;++i)
        {
            cin>>a[i]>>b[i];
            tot[++j]=a[i];
            tot[++j]=b[i];
            fv[i]=fvf[i]=fvf[i+n]=ocp[i]=ocp[i+n]=fv[i+n]=0;
        }
        fv[2*n+1]=fvf[2*n+1]=ocp[2*n+1]=fv[2*n+2]=fvf[2*n+2]=ocp[2*n+2]=0;
        sort(tot+1,tot+j+1);
        k=0;
        for(i=1;i<=j;++i)
            if(i==1 || tot[i]!=tot[i-1])
                newval[tot[i]]=++k;
        for(i=1;i<=n;++i)
        {
            a[i]=newval[a[i]];
            b[i]=newval[b[i]];
            ++fv[a[i]];
            --fv[b[i]];
        }
        for(i=1;i<=2*n+2;++i)
            fv[i]+=fv[i-1];
        for(i=1;i<=2*n+2;++i)
            if(fv[i] && fv[i+1]==0)
                ++cnt;
        for(i=1;i<=n;++i)
        {
            if(fv[b[i]]==1)
                fvf[b[i]]=1;
            if(a[i]==b[i])
            {
                if(ocp[a[i]]==0)
                {
                    ocp[a[i]]=1;
                    if(fv[a[i]]==0 && fv[a[i]-1]==0)
                        ++cnt;
                }
            }
        }
        for(i=1;i<=2*n+2;++i)
            fvf[i]+=fvf[i-1];
        mx=0;
        for(i=1;i<=n;++i)
            mx=max(mx,cnt+fvf[b[i]-1]-fvf[a[i]-1]-((fv[b[i]]==0)&(ocp[b[i]]==0)&(fv[b[i]-1]==1)));
        cout<<min(mx,n-1)<<'\n';
    }
    return 0;
}