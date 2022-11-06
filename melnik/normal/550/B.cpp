#include <iostream>
#include <algorithm>
using namespace std;
int i[20],n,l,r,x,o[20],kol=0;

void prov()
{
    int sum=0,mi=2e9,ma=-1;
    for (int k=0;k<n;k++)
    sum+=i[k]*o[k];
    for (int k=0;k<n;k++) ma=max(ma,i[k]*o[k]);
    for (int k=0;k<n;k++) if (o[k]!=0) mi=min(mi,i[k]);
    if (l<=sum&&r>=sum&&ma-mi>=x) kol++;
}
void per(int k)
{
    if (k==n) prov(); else
    for (int y=0;y<2;y++)
    {
        o[k]=y;
        per(k+1);
    }
}
int main()
{
    int k;
    cin>>n>>l>>r>>x;
    for (k=0;k<n;k++)
    cin>>i[k];
    per(0);
    cout<<kol;
    return 0;
}