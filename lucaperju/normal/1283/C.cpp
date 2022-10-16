#include <bits/stdc++.h>
using namespace std;
int v[200005];
int ocp[200005],ocpi[200005];
void creste (int &j)
{
    ++j;
    while(ocp[j]==-1)
        ++j;
}
int main()
{
    int n,t,i,j,k=0,pas=1<<20,m,mx=0,sc,rz;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        ++ocp[v[i]];
        ++ocpi[v[i]];
    }
    for(i=1;i<=n;++i)
        if(ocp[i]==0 && v[i]==0)
            ocp[++k]=i;
    if(k>1)
    {
    for(i=1;i<k;++i)
        v[ocp[i]]=ocp[i+1];
    v[ocp[k]]=ocp[1];
    }
    else if (k==1)
    {
        for(i=1;i<=n;++i)
        {
            if(i!=ocp[1] && ocpi[i]==0)
            {
                v[ocp[1]]=i;
                break;
            }
        }
    }
    for(i=1;i<=n;++i)
        ocp[i]=ocpi[i]=0;
    for(i=1;i<=n;++i)
    {
        ++ocp[v[i]];
        ++ocpi[v[i]];
    }
    k=0;
    for(i=1;i<=n;++i)
        if(ocp[i]==0)
            ocp[++k]=i;
    j=0;
    for(i=1;i<=n;++i)
        if(v[i]==0)
            v[i]=ocp[++j];
    for(i=1;i<=n;++i)
        cout<<v[i]<<' ';
    return 0;
}