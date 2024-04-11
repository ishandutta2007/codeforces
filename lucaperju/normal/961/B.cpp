#include <iostream>

using namespace std;
int v[100005],a[100005];
int main()
{
    int n,k,s=0,i,j,cnt,mx=0;
    cin>>n>>k;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]==1)
            s+=v[i],v[i]=0;
        v[i]+=v[i-1];
    }
    for(i=k;i<=n;++i)
    {
        if(v[i]-v[i-k]>mx)
            mx=v[i]-v[i-k];
    }
    cout<<mx+s;
    return 0;
}