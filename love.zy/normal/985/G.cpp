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
  
const int maxn=200005;
ull A,B,C;
ull n,m;
int du[maxn],e[maxn][2];
vi g[maxn],s[maxn];
ull ans0,ans1,ans2,ans3;
ull label[maxn];
ull tmp[3];

ull cal(ull a,ull b,ull c)
{
    tmp[0]=a;tmp[1]=b;tmp[2]=c;
    sort(tmp,tmp+3);
    return A*tmp[0]+B*tmp[1]+C*tmp[2];
}

int main()
{
    scanf("%llu%llu",&n,&m);
    scanf("%llu%llu%llu",&A,&B,&C);
    for(ull i=0;i<m;i++)
    {
        ull x,y;
        scanf("%llu%llu",&x,&y);
        if(x>y)swap(x,y);
        s[x].pb(y);s[y].pb(x);
        e[i][0]=x;e[i][1]=y;
        du[x]++;du[y]++;
    }
    for(ull i=0;i<m;i++)
    {
        int x=e[i][0],y=e[i][1];
        if(du[x]<du[y])g[x].pb(y);else g[y].pb(x);
    }
    //ans0
    for(ull i=1;i<n-1;i++)
    {
        ull pre = i*(i-1)/2;
        ull suf = (n+i)*(n-i-1)/2;
        ans0 += A*pre*(n-1-i) + B*i*(n-1-i)*i + C*suf*i;
    }
    //ans1
    for(ull i=0;i<m;i++)
    {
        ull x=e[i][0],y=e[i][1];
        ull pre = x*(x-1)/2;
        ull suf = (n+y)*(n-y-1)/2;
        ans1 += A*pre + B*x*x + C*y*x;
        ans1 += A*x*(n-1-y) + B*y*(n-1-y) + C*suf;
        if(y-x>1)
        {
            ull mid = (x+y)*(y-x-1)/2;
            ans1 += A*x*(y-x-1) + B*mid + C*y*(y-x-1);
        }
    }
    //ans2
    for(ull i=0;i<n;i++)
    {
        if(s[i].size()<2)continue;
        sort(s[i].begin(),s[i].end());
        ull precnt = 0, sufcnt = 0, pre = 0, suf = 0;
        for(ull p : s[i])
        {
            if(p>i)break;
            ans2 += A*pre + B*p*precnt + C*i*precnt;
            precnt ++;
            pre += p;
        }
        for(int j=(int)s[i].size()-1;j>=0;j--)
        {
            ull p=s[i][j];
            if(p<i)break;
            ans2 += A*i*sufcnt + B*p*sufcnt + C*suf;
            sufcnt ++;
            suf += p;
        }
        ans2 += A*pre*sufcnt + B*i*precnt*sufcnt + C*precnt*suf;
    }
    //ans3
    for(ull i=0;i<n;i++)label[i]=n+1;
    for(ull i=0;i<m;i++)
    {
        ull x=e[i][0],y=e[i][1];
        for(int p : g[x])label[p]=x;
        for(int p : g[y])
        {
            if(label[p]!=x)continue;
            ans3+=cal(x,y,p);
        }
    }
    printf("%llu\n",ans0-ans1+ans2-ans3);
    return 0;
}