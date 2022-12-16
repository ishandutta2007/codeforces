#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,m,k;
long long pref[nmax];
long long add[nmax],rem[nmax];
long long val[nmax];
int main()
{
scanf("%i%i%i",&n,&m,&k);
int l,r,x,p;
for(int i=1;i<=m;i++)
{
    scanf("%i%i%i",&l,&r,&x);
    x--;
    pref[l]+=x;
    pref[r+1]-=x;

    add[l]++;
    add[r+1]--;

    rem[r+1]+=(r-l+1);
}


long long sum=0,add_now=0;
for(int i=1;i<=n;i++)
{
    add_now=add_now+add[i];
    sum=sum+pref[i]+add_now-rem[i];
    val[i]=sum;
    //cout<<i<<" -> "<<sum<<" "<<add[i]<<endl;
}

long long ans=0;
for(int i=1;i<=k;i++)
{
    scanf("%i",&p);
    ans=ans+val[p];
}

printf("%I64d\n",ans);
return 0;
}