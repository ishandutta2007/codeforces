#include <bits/stdc++.h>
using namespace std;
int v[400005],pr[200005];
const int N=2750131;
bool ciur[N+5];
int fv[N+5],pz[N+5];
int main ()
{
    long long n,m,ta,tb,k=0,i,j,nrc=0,nrd=0,s=0,t;
    cin>>n;
    for(i=1;i<=2*n;++i)
    {
        cin>>v[i];
        ++fv[v[i]];
    }
    ciur[1]=ciur[0]=1;
    for(i=2;i<=N;++i)
    {
        if(!ciur[i])
        {
            for(j=i*i;j<=N;j+=i)
                ciur[j]=1;
            pr[++k]=i;
        }
    }
    for(i=1;i<=k;++i)
        pz[pr[i]]=i;
    sort(v+1,v+2*n+1);
    n<<=1;
    for(i=n;i>=1;--i)
    {
        if(fv[v[i]])
        {
            if(!ciur[v[i]])
            {
                --fv[pz[v[i]]];
                cout<<pz[v[i]]<<' ';
            }
            else
            {
                for(j=2;j*j<=v[i] && v[i]%j;++j);
                --fv[v[i]/j];
                cout<<v[i]<<' ';
            }
            --fv[v[i]];
        }
    }
    return 0;
}