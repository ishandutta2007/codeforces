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

int a[26],n,m,k,T;
int dp[30005];
char s[200005];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        scanf("%s",s+1);
        for(int i=0;i<26;i++)a[i]=0;
        for(int i=1;i<=k;i++)a[s[i]-'A']++;
        int nm=max(n,m);
        for(int i=0;i<=nm+1;i++)dp[i]=0;
        dp[nm+1]=k+1;dp[0]=1;
        for(int i=0;i<26;i++)
        {
            if(a[i]==0)continue;
            for(int mask=nm;mask>=0;mask--)
            {
                if(dp[mask]==0)continue;
                if(mask+a[i]>nm)dp[nm+1]=min(dp[nm+1],mask+a[i]);
                else dp[mask+a[i]]=mask+a[i];
            }
        }
        bool f=false;
        for(int i=n;i<=nm+1;i++)
            if(dp[i]>0 && k-dp[i]>=m){f=true;break;}
        if(f){puts("0");continue;}
        LL ans = 1e18;
        for(int id=0;id<26;id++)
        {
            if(a[id]==0)continue;
            for(int i=0;i<=nm+1;i++)dp[i]=0;
            dp[0]=1;
            for(int i=0;i<26;i++)
            {
                if(i==id || a[i]==0)continue;
                for(int mask=nm;mask>=0;mask--)
                {
                    if(dp[mask]==0)continue;
                    if(mask+a[i]>nm)dp[nm+1]=min(dp[nm+1],mask+a[i]);
                    else dp[mask+a[i]]=mask+a[i];
                }
            }
            int sum=k-a[id];
            for(int j=n;j>=0;j--)
            {
                if(dp[j]==0)continue;
                if(j+a[id]<n)break;
                int tmp=sum-j;
                if(n+m-sum<=a[id] && tmp<=m) ans = min(ans,1ll*(n-j)*(m-tmp));
            }
            for(int j=m;j>=0;j--)
            {
                if(dp[j]==0)continue;
                if(j+a[id]<m)break;
                int tmp=sum-j;
                if(n+m-sum<=a[id] && tmp<=n) ans = min(ans,1ll*(m-j)*(n-tmp));
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}