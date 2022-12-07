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

const int maxn=500005;
struct edge
{
    int x,y,w;
    void read(){scanf("%d%d%d",&x,&y,&w);}
}e[maxn];

int fa[maxn],fval[maxn];
void Init(int n) {
    for(int i=0;i<=n;i++)
        fa[i]=i,fval[i]=0;
}
int fnd(int x) {
    while(x!=fa[x])x=fa[x];
    return x;
}
stack<int> rec;
stack<pair<int*,int>>S;
void join(int x,int y,bool on,int num) {
    x=fnd(x),y=fnd(y);
    if(x==y)return;
    if(fval[x]<=fval[y]) {
        if(on)
        {
            rec.push(num);
            S.push(make_pair(&fa[x],fa[x]));
        }
        fa[x]=y;
        if(fval[x]==fval[y]) {
            if(on) 
            {
                rec.push(num);
                S.push(make_pair(&fval[y],fval[y]));
            }
            fval[y]++;
        }
    }
    else {
        if(on)
        {
            rec.push(num);
            S.push(make_pair(&fa[y],fa[y]));
        }
        fa[y]=x;
    }
}
void back(bool on,int num) {
    while(!S.empty()) {
        if(on) 
        {
            if(rec.top()!=num)break;
            *S.top().first=S.top().second;
        }
        S.pop();rec.pop();
    }
}
int n,m,lb[maxn],q;
int lsh[maxn],ls[maxn],cc;
bool ans[maxn];
vector< pair<int , vi > > g[maxn];

bool cmp(int x,int y){return e[x].w<e[y].w;}

int main()
{
    scanf("%d%d",&n,&m);
    Init(n);
    for(int i=1;i<=m;i++)
    {
        e[i].read();
        lsh[i]=e[i].w;
    }
    for(int i=1;i<=m;i++)lb[i]=i;
    sort(lb+1,lb+m+1,cmp);
    sort(lsh+1,lsh+m+1);
    ls[cc=1]=lsh[1];
    for(int i=2;i<=m;i++)
        if(lsh[i]!=lsh[i-1])ls[++cc]=lsh[i];
    scanf("%d",&q);
    for(int i=1;i<=q;i++)ans[i]=true;
    for(int mask=1;mask<=q;mask++)
    {
        int k;
        scanf("%d",&k);
        vi now;now.clear();
        for(int i=1;i<=k;i++)
        {
            int x;
            scanf("%d",&x);
            now.pb(x);
        }
        sort(now.begin(),now.end(),cmp);
        vi temp;temp.clear();
        for(int u : now)
        {
            if(temp.size()==0)
            {
                temp.pb(u);
                continue;
            }
            if(e[u].w==e[temp[0]].w)temp.pb(u);
            else
            {
                int s=lower_bound(ls+1,ls+cc+1,e[temp[0]].w)-ls;
                g[s].pb(mp(mask,temp));
                temp.clear();temp.pb(u);
            }
        }
        if(temp.size()>0)
        {
            int s=lower_bound(ls+1,ls+cc+1,e[temp[0]].w)-ls;
            g[s].pb(mp(mask,temp));
        }
    }
    int cnt=cc;
    int l=1;
    for(int mask=1;mask<=cc;mask++)
    {
        for(unsigned int i=0;i<g[mask].size();i++)
        {
            int bl=g[mask][i].fi;
            if(!ans[bl])continue;
            //if(mask==4 && bl==5)printf("111111\n");
            vi temp=g[mask][i].se;
            cnt++;
            for(int p : temp)
            {
                if(fnd(e[p].x)==fnd(e[p].y))
                {
                    ans[bl]=false;
                    break;
                }
                join(e[p].x,e[p].y,1,cnt);
            }
            back(1,cnt);
        }
        while(l<=m && e[lb[l]].w<=ls[mask])
        {
            join(e[lb[l]].x,e[lb[l]].y,1,mask);
            l++;
        }
    }
    for(int i=1;i<=q;i++)if(ans[i])printf("YES\n");else printf("NO\n");
    return 0;
}