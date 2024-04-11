#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42,inf=1e4+1;
int n,a[nmax];
double arr[nmax];
double query(double x)
{
for(int i=1;i<=n;i++)arr[i]=a[i]-x;
double ans=0;

double min_sum=0,max_sum=0,sum=0;

for(int i=1;i<=n;i++)
{
    sum=sum+arr[i];
    min_sum=min(min_sum,sum);
    max_sum=max(max_sum,sum);

    ans=max(ans,max_sum-sum);
    ans=max(ans,sum-min_sum);
}
return ans;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
/*
for(double x=-10;x<=10;x=x+0.1)
    cout<<x<<" -> "<<query(x)<<endl;
*/

double l=-inf,r=inf;
double val_l=query(l),val_r=query(r);
for(int i=1;i<=150;i++)
{
    double l1=l+(r-l)/3,r1=r-(r-l)/3;
    if(query(l1)>query(r1))l=l1;
    else r=r1;
}
//cout<<l<<endl;
printf("%.18f\n",query(l));
return 0;
}