#include <bits/stdc++.h>
using namespace std;
int fv[100005];
int vc[100005];
int main()
{
    long long t,n,s,m,i,j,x,y,l,r;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            fv[i]=0;
        int mx=0;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            ++fv[a];
            mx=max(mx,fv[a]);
        }
        j=0;
        for(i=1;i<=n;++i)
        {
            if(fv[i])
                vc[++j]=fv[i];
        }
        int cnt=0;
        for(i=1;i<=n;++i)
            if(fv[i]==mx)
                ++cnt;
        sort(vc+1,vc+j+1);
        long long rz=0;
        for(i=1;i<=n;++i)
        {
            if(i>j)
                break;
            if((n-cnt)/(i+1)+1<mx)
                break;
            rz=i;
        }
        cout<<rz<<'\n';
    }
    return 0;
}