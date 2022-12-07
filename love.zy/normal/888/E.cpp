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
 
int n,m,s1,s2,c=0;
LL a[36],s[1000005];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    s1=n>>1,s2=n-(n>>1);
    for(int mask=0;mask<(1<<s1);mask++)
    {
        LL sum=0;
        for(int i=0;i<s1;i++)
            if((mask>>i)&1)sum+=a[i+1];
        s[mask+1]=sum%m;
    }
    sort(s+1,s+(1<<s1)+1);
    s[(1<<s1)+1]=m;
    LL ans=0;
    for(int mask=0;mask<(1<<s2);mask++)
    {
        LL sum=0;
        for(int i=0;i<s2;i++)
            if((mask>>i)&1)sum+=a[s1+i+1];
        sum%=m;
        int u=lower_bound(s+1,s+(1<<s1)+2,m-sum)-s;
        ans=max(ans,sum+s[u-1]);
    }
    printf("%lld\n",ans);
    return 0;
}