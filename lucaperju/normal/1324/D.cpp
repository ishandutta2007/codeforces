#include <bits/stdc++.h>

using namespace std;
struct ura
{
    int a,b;
}v[200005];
int v2[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,ok=0,i,j,cnt=4;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i].a;
    }
    for(i=1;i<=n;++i)
    {
        cin>>v[i].b;
        v2[i]=v[i].b-v[i].a;
    }
    sort(v2+1,v2+n+1);
    for(i=1;i<=n;++i)
    {
        int pas=1<<20,k=0;
        while(pas)
        {
            if(k+pas<=n && v2[k+pas]<v[i].a-v[i].b)
                k+=pas;
            pas>>=1;
        }
        ok+=k;
        if(v[i].a>v[i].b)
            --ok;
    }
    cout<<ok/2;
    return 0;
}