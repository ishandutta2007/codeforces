/*****************************************
Author: lizi
Email: lzy960601@outlook.com
****************************************/
  
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

const int maxn=5005;
int n,m,w,qu;
pair<int,int> rr[maxn];
queue<int> q;
vector<int> g[maxn];
bool vis[maxn];
int dis[maxn],ma;
struct node
{
    int point,cnt;
    LL price;
    bool operator < (const struct node &p)const
    {return price<p.price;}
}a[5005];

void BFS(int st)
{
    for(int i=1;i<=n;i++)vis[i]=false,dis[i]=maxn;
    while(!q.empty())q.pop();
    ma=0;
    q.push(st);dis[st]=0;vis[st]=true;
    while(!q.empty())
    {
        int t=q.front();q.pop();
        for(int p : g[t])
        {
            if(vis[p])continue;
            dis[p]=min(dis[p],dis[t]+1);
            vis[p]=true;ma=max(ma,dis[p]);
            q.push(p);
        }
    }
}

bool check(int lim,int cnt,LL pri)
{
    int sum=0;
    LL tot=0;
    bool f=true;
    for(int i=1;i<=w;i++)
    {
        if(dis[a[i].point]>lim)continue;
        int x=min(cnt-sum,a[i].cnt);
        sum+=x;tot+=1ll*x*a[i].price;
        if(tot+1ll*(cnt-sum)*a[i].price>pri){f=false;break;}
        if(sum>=cnt)break;
    }
    return f && sum>=cnt && tot<=pri;
}

int main()
{
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].pb(y);g[y].pb(x);
    }
    scanf("%d",&w);
    for(int i=1;i<=w;i++)
    {
        int c,k,p;
        scanf("%d%d%d",&c,&k,&p);
        a[i]={c,k,p};
    }
    sort(a+1,a+w+1);
    scanf("%d",&qu);
    while(qu--)
    {
        int nd,num;
        LL pri;
        scanf("%d%d%lld",&nd,&num,&pri);
        BFS(nd);
        if(!check(ma,num,pri)){printf("-1\n");continue;}
        int l=0,r=ma;
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            if(check(mid,num,pri))r=mid;else l=mid;
        }
        if(!check(l,num,pri))l++;
        printf("%d\n",l);
    }
    return 0;
}