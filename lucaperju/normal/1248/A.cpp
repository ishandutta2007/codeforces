#include <iostream>
#include <algorithm>
using namespace std;

//int p[100005],q[10005];
int main()
{
    long long t,x,n,m,nr,nri,nrp,nrii,nrpp,i,j,mij,st,dr;
    cin>>t;
    for (i=1;i<=t;i++)
    {
        cin>>n;
        nr=nri=nrp=nrii=nrpp=0;
        for (j=1;j<=n;j++)
        {
            cin>>x;
            if (x%2==0)
                nrp++;
            else
                nri++;
        }
        cin>>m;
        for (j=1;j<=m;j++)
        {
            cin>>x;
            if (x%2==0)
                nrpp++;
            else
                nrii++;
        }
        cout<<nrpp*nrp+nrii*nri<<'\n';
    }
    return 0;
}