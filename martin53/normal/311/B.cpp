#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,m,p;
int arr[nmax];
long long pref[nmax],when[nmax];
long long dp[nmax][105];
long long cost(int l,int r)
{
    //cout<<l<<" "<<r<<" -> "<<1LL*(r-l+1)*(when[r])-pref[r]+pref[l-1]<<endl;
    return 1LL*(r-l+1)*(when[r])-pref[r]+pref[l-1];
}
int brute_force(int f,int i,int l,int r)
{
    r=min(r,i);
    dp[i][f]=1e18;
    int where=0;
    long long c;
    for(int j=l;j<=r;j++)
    {
        c=dp[j-1][f-1]+cost(j,i);
        if(c<dp[i][f])
        {
        where=j;
        dp[i][f]=c;
        }
    }
    return where;
}
void run(int f,int lq,int rq,int l,int r)
{
    if(l==r)
    {
        brute_force(f,l,lq,rq);
        return;
    }
    if(l>r)return;
    rq=min(rq,r);
    int av=(l+r)/2;
    int d=brute_force(f,av,lq,rq);

    //cout<<lq<<" "<<rq<<" "<<l<<" "<<r<<" -> "<<av<<" "<<d<<endl;

    run(f,lq,d,l,av-1);
    run(f,d,rq,av+1,r);
}
int main()
{
scanf("%i%i%i",&n,&m,&p);
for(int i=1;i<n;i++)scanf("%i",&arr[i]);
for(int i=1;i<n;i++)
    pref[i]=pref[i-1]+arr[i];
int h,t;
for(int i=1;i<=m;i++)
{
    scanf("%i%i",&h,&t);
    h--;
    when[i]=t-pref[h];
}
sort(when+1,when+m+1);
for(int j=1;j<=m;j++)
    pref[j]=pref[j-1]+when[j];
//for(int j=1;j<=m;j++)cout<<when[j]<<" ";cout<<endl;
p=min(p,m);
for(int i=1;i<=m;i++)
    dp[i][1]=cost(1,i);
for(int i=2;i<=p;i++)
    run(i,i-1,m,i,m);
/*
for(int i=1;i<=p;i++)
{
    for(int j=1;j<=m;j++)cout<<dp[j][i]<<" ";cout<<endl;
}
*/
printf("%lld\n",dp[m][p]);
return 0;
}