#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,m,x[nmax];
long long sum_l[nmax],sum_r[nmax];
void calc_l()
{
    long long s=x[0];
    for(int i=1;i<n;i++)
    {
        sum_l[i]=1LL*x[i]*((i-1)/m+1)-s;
        if(i%m==0)s=s+x[i];
    }

}

void calc_r()
{
    reverse(x,x+n);
    long long s=x[0];
    for(int i=1;i<n;i++)
    {
        sum_r[i]=s-1LL*x[i]*((i-1)/m+1);
        if(i%m==0)s=s+x[i];
    }
    reverse(sum_r,sum_r+n);
    reverse(x,x+n);
}

int main()
{
scanf("%i%i",&n,&m);
for(int i=0;i<n;i++)scanf("%i",&x[i]);

calc_l();
calc_r();

long long ans=1e18;
for(int i=0;i<n;i++)
{
    int j=i;
    while(j<n&&x[i]==x[j])j++;
    j--;
    ans=min(ans,sum_l[i]+sum_r[j]);
    i=j;
}
cout<<ans*2<<endl;
return 0;
}