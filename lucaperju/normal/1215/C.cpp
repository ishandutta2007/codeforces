#include <bits/stdc++.h>
using namespace std;
char a[200005],b[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,i,j,m,k=0,t,s=0,rz=0,fva=0,fvb=0;
    cin>>n;
    cin>>(a+1)>>(b+1);
    long long nrb2=0,ok=0;
    for(i=1;i<=n;++i)
    {
        fva+=(a[i]=='a')+(b[i]=='a');
        fvb+=(a[i]=='b')+(b[i]=='b');
        nrb2+=(b[i]=='b');
        ok+=((a[i]=='b')&&(b[i]=='b'));
    }
    if(fva%2!=0 || fvb%2!=0)
    {
        cout<<-1;
        return 0;
    }
    fvb-=2*ok;
    nrb2-=ok;
    if(fvb%2==1 || nrb2%2==1)
        s+=2+fvb/2-1;
    else
        s+=fvb/2;
    cout<<s<<'\n';
    int pzpr=-1;
    for(i=1;i<=n;++i)
    {
        if(a[i]=='b' && b[i]=='a')
        {
            if(pzpr==-1)
                pzpr=i;
            else
            {
                cout<<pzpr<<' '<<i<<'\n';
                pzpr=-1;
            }
        }
    }
    int pz=pzpr;
    pzpr=-1;
    for(i=1;i<=n;++i)
    {
        if(b[i]=='b' && a[i]=='a')
        {
            if(pzpr==-1)
                pzpr=i;
            else
            {
                cout<<i<<' '<<pzpr<<'\n';
                pzpr=-1;
            }
        }
    }
    if(pz!=-1)
    {
        cout<<pz<<' '<<pz<<'\n';
        cout<<pzpr<<' '<<pz;
    }
    return 0;
}