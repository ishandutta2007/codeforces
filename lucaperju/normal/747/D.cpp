#include <bits/stdc++.h>

using namespace std;
long long v[200005],a[200005];
int main()
{
    long long i,j=0,n,mn=9999999999,k,cnt=0,pz=-1,cur=-1;
    cin>>n>>k;
    for(i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]<0)
            a[i]=-1;
        else
            a[i]=1;
        if(a[i]==-1 && cur==-1)
            cur=i;
        if(a[i]==1 && a[i-1]==-1 && pz==-1)
            pz=i-1;
        if(a[i]==-1 && pz!=-1)
            v[++j]=i-pz-1,pz=-1;
    }
    sort(v+1,v+j+1);
    int ccur=cur;
    if(cur==-1)
    {
        cout<<0;
        return 0;
    }
    if(a[n]!=-1)
    {
        cnt=2;
        cur=pz-cur+1;
        for(i=j;i>=1 && cur>k;--i)
        {
            cnt+=2;
            cur-=v[i];
        }
        if(cur<=k)
            mn=min(mn,cnt);
    }
    cur=ccur;
    cnt=1;
    cur=n-cur+1;
    for(i=j;i>=1 && cur>k;--i)
    {
        cnt+=2;
        cur-=v[i];
    }
    if(cur<=k)
        mn=min(mn,cnt);
    if(mn!=9999999999)
        cout<<mn;
    else
        cout<<-1;
}