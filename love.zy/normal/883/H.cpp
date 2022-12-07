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

int convert(char s)
{
    if(s<='9')return s-48;
    if(s<='Z')return s-65+10;
    return s-97+36;
}

char nconvert(int s)
{
    if(s<=9)return s+48;
    if(s<=35)return s-10+65;
    return s+97-36;
}

const int maxn=400005;
char s[maxn],ans[maxn];
int cnt[105],sum[2],n;
vi g,ji,ou;

int main()
{   
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++)cnt[convert(s[i])]++;
    for(int i=0;i<=62;i++)
    {
        if(!cnt[i])continue;
        sum[cnt[i]&1]++;
        if(cnt[i]&1)
        {
            for(int j=1;j<=cnt[i]-1;j++)ou.pb(i);
            ji.pb(i);
        }else
        {
            for(int j=1;j<=cnt[i];j++)ou.pb(i);
        }
    }
    if(sum[1]==0)
    {
        printf("1\n");
        sort(s,s+n);
        int l=0,r=n-1;
        for(int i=0;i<n;i+=2)
        {
            ans[l++]=s[i];
            ans[r--]=s[i+1];
        }
        ans[n]=0;
        printf("%s\n",ans);
        return 0;
    }
    for(int i=1;i*i<=n;i++)
    {
        if(n%i!=0)continue;
        if((n/i)&1)g.pb(i);
        if(i&1)g.pb(n/i);
    }
    sort(g.begin(),g.end());
    int now;
    for(int p : g)
    {
        if(p<sum[1])continue;
        now=p;break;
    }
    int len=n/now;
    printf("%d\n",now);
    int cj=0,co=0,coo=(int)ou.size()-1;
    while(now--)
    {
        int l=0,r=len-1;ans[len]=0;
        for(int i=0;i<((len-1)>>1);i++)
        {
            ans[l++]=ans[r--]=nconvert(ou[co]);
            co+=2;
        }
        if(cj>=ji.size())
        {
            ans[l]=nconvert(ou[coo--]);
        }else ans[l]=nconvert(ji[cj++]);
        printf("%s",ans);
        if(now>0)printf(" ");else printf("\n");
    }
    return 0;
}