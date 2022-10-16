#include <bits/stdc++.h>
 
using namespace std;
int a[200005],b[200005];
const int mod=998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unsigned long long m,k,t,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0,n;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>a[i];
    for(i=1;i<=m;++i)
        cin>>b[i];
    for(i=1;i<=n;++i)
    {
        if(a[i]<b[1])
        {
            cout<<0;
            return 0;
        }
    }
    for(i=n;i>=1;--i)
    {
        if(a[i]==b[m])
            break;
        else if(a[i]<b[m])
        {
            cout<<"0";
            return 0;
        }
    }
    if(i==0)
    {
        cout<<0;
        return 0;
    }
    int cnt=0,cat=1;
    j=m-1;
    --i;
    long long rz=1;
    for(;i>=1 && j>=1;--i)
    {
        cnt+=cat;
        if(a[i]==b[j])
        {
            rz=(rz*1LL*cnt)%mod;
            cnt=0;
            --j;
            cat=1;
        }
        else if(a[i]>b[j] && a[i]<b[j+1])
        {
            cat=0;
        }
        else if(a[i]<b[j])
        {
            cout<<0;
            return 0;
        }
    }
    if(j!=0)
    {
        cout<<0;
        return 0;
    }
    cout<<rz<<'\n';
    return 0;
}