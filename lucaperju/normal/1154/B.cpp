#include <bits/stdc++.h>
using namespace std;
long long v[105];
int main()
{
    ios_base::sync_with_stdio(0);
    long long p,add=1,t,h,n,i,j,mn=99999,k=0,mx=-9999999LL,tot,m,obj,cnt=0,cnti=0,s=0,nri=0,b2,a3,b3,pz=1;
    int i1=-1,j1=-1,i2=-1,j2=-1;
    int a,b,c,d;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        mn=min(mn,v[i]);
        mx=max(mx,v[i]);
    }
    int vl=-1;
    for(i=1;i<=n;++i)
    {
        if(v[i]!=mx && v[i]!=mn)
        {
            if(vl!=-1 && vl!=v[i])
            {
                cout<<-1;
                return 0;
            }
            vl=v[i];
        }
    }
    if(vl!=-1)
    if(mx-vl!=vl-mn)
    {
        cout<<-1;
        return 0;
    }
    if(vl!=-1)
    cout<<mx-vl;
    else
    {
        if((mx-mn)%2==0)
            cout<<(mx-mn)/2;
        else
            cout<<mx-mn;
    }
    return 0;
}