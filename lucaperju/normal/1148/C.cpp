#include <bits/stdc++.h>
using namespace std;
int v[300005],a[2000006],b[2000006],pz[300005];
int main ()
{
    long long n,m,ta,tb,k=0,i,j;
    long long mn=0LL;
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i];
        pz[v[i]]=i;
    }
    for(i=2; i<n; ++i) /// ----------
    {
        int ci=i;
        i=pz[i];
        if(i<=n/2)
        {
            a[++k]=i;
            b[k]=n;
            swap(pz[v[i]],pz[v[n]]);
            swap(v[i],v[n]);
            if(v[n]<=n/2)
            {
                a[++k]=v[n];
                b[k]=n;
                swap(pz[v[n]],pz[v[v[n]]]);
                swap(v[n],v[v[n]]);
            }
            else
            {
                b[++k]=n;
                a[k]=1;
                swap(pz[v[n]],pz[v[1]]);
                swap(v[n],v[1]);
                a[++k]=1;
                b[k]=v[1];
                swap(pz[v[1]],pz[v[v[1]]]);
                swap(v[1],v[v[1]]);
            }
        }
        else
        {
            a[++k]=1;
            b[k]=i;
            swap(pz[v[1]],pz[v[i]]);
            swap(v[1],v[i]);
            if(v[1]>n/2)
            {
                a[++k]=1;
                b[k]=v[1];
                swap(pz[v[1]],pz[v[v[1]]]);
                swap(v[1],v[v[1]]);
            }
            else
            {
                b[++k]=n;
                a[k]=1;
                swap(pz[v[n]],pz[v[1]]);
                swap(v[n],v[1]);
                a[++k]=v[n];
                b[k]=n;
                swap(pz[v[n]],pz[v[v[n]]]);
                swap(v[n],v[v[n]]);
            }
        }
        i=ci;
    }
    if(v[1]!=1)
    {
        a[++k]=1;
        b[k]=n;
    }
    cout<<k<<'\n';
    for(i=1; i<=k; ++i)
        cout<<a[i]<<' '<<b[i]<<'\n';
    return 0;
}