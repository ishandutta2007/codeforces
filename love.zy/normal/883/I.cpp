/*****************************************
Author: lizi
Email: lzy960601@outlook.com
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn=300005;
int n,k;
int a[maxn];
int dp[maxn];

bool check(int c)
{
    for(int i=0;i<=k;i++)dp[i]=1;
    if(a[k]-a[1]<=c)dp[k]=2;
    int l=0,r=k;
    while(r<n)
    {
        //bool f=true;
        r++;
        while(a[r]-a[l+1]>c)l++;
        dp[r]=0;
        if(r-l>=k && l>0 && dp[r-k]-dp[l-1]>0)dp[r]=1;
        if(dp[r]==0 && l==0)dp[r]=1;
        dp[r]+=dp[r-1];
    }
    return dp[n]-dp[n-1]>0;
}

int main()
{
    scanf("%d%d",&n,&k);
    if(n==1){printf("0\n");return 0;}
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    if(n<2*k){printf("%d\n",a[n]-a[1]);return 0;}
    int l=0,r=1e9;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        if(check(mid))r=mid;else l=mid;
    }
    if(!check(l))l++;
    printf("%d\n",l);
    return 0;
}