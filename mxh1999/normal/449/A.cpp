#include<cstdio>
#include<iostream>
using namespace std;

typedef long long ll;
int n,m,k;

ll sol(int x)
{
    ll ans1=n/(x+1),ans2=m/(k-x+1);
    return ans1*ans2;
}
int main()
{
    int i,j=-1;
    ll max=0;
    scanf("%d%d%d",&n,&m,&k);
    if (n-1+m-1<k)  {printf("-1\n");return 0;}
    int l=0,r=k;
    if (k-l>m-1)    l=k-m+1;
    if (r>n-1)  r=n-1;
    ll t=sol(l);j=l;
    if  (sol(r)>t)  {t=sol(r);j=r;}
    if  (sol((l+r)/2)>t)    {t=sol((l+r)/2);j=(l+r)/2;}
    cout<<t<<endl;
    return 0;
}