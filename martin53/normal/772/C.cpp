#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n,m;
int order[nmax];
bool blocked[nmax];
bool cmp(int a,int b)
{
    return __gcd(a,m)<__gcd(b,m);
}
pair<int/*value*/,int/*number*/> dp[nmax],help[nmax];
vector<int> divs;
int extended(int a,int b)
{
    int a_=a,b_=b;

    int s1=1,s2=0,s3;
    int t1=0,t2=1,t3;
    while(b)
    {
        int p=a/b,q=a%b;
        s3=s1-p*s2;
        t3=t1-p*t2;

        t1=t2;
        t2=t3;

        s1=s2;
        s2=s3;

        a=b;
        b=q;
        //cout<<a_<<" "<<s3<<" "<<b_<<" "<<t3<<" -> "<<a_*s3+b_*t3<<" "<<a<<" "<<b<<endl;
    }
    if(s1<0)s1=s1+b_,t1=t1-a_;
    assert(0<=s1&&s1<m);
    return s1;
}
int my_move(int a,int b)
{
    //cout<<"my move "<<a<<" "<<b<<" -> ";
    int d=__gcd(a,m);
    a=a/d;
    b=b/d;
    int m_=m/d;
    //cout<<1LL*extended(a,m_)*b%m<<endl;
    return 1LL*extended(a,m_)*b%m;
}
int arr[nmax],id=0;
int main()
{
scanf("%i%i",&n,&m);
int x;
for(int i=1;i<=n;i++)
{
    scanf("%i",&x);
    blocked[x]=1;
}
for(int j=1;j<=m;j++)
    if(m%j==0)divs.push_back(j);
n=0;
for(int i=0;i<m;i++)
    if(blocked[i]==0)
    {
    order[n]=i;
    n++;
    }
sort(order,order+n,cmp);
for(int i=n-1;i>=0;i--)
{
int g=__gcd(m,order[i]);
dp[i]={help[g].first+1,help[g].second};
    for(auto k:divs)
        if(g%k==0)
        {
            if(help[k].first<dp[i].first)help[k]={dp[i].first,i};
        }
    //cout<<i<<" -> "<<order[i]<<" "<<dp[i].first<<" "<<dp[i].second<<endl;
}
int mx=0;
for(int i=0;i<n;i++)
    if(dp[mx].first<dp[i].first)mx=i;
printf("%i\n",dp[mx].first);
int now=mx;
arr[++id]=order[now];
for(int j=2;j<=dp[mx].first;j++)
{
    now=dp[now].second;
    arr[++id]=order[now];
}
printf("%i",arr[1]);
for(int i=2;i<=id;i++)
    printf(" %i",my_move(arr[i-1],arr[i]));
printf("\n");
return 0;
}