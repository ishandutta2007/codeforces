
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
const int maxn=1000005;
struct node
{
    int pos,lb;
    bool operator < (const struct node &p)const
    {return pos<p.pos;}
};
vector<node> g[maxn];
vi ans;
int a[maxn][2],n,s[maxn];
int cc,ls[maxn],lsh[maxn];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i][0]=x;a[i][1]=y;
        lsh[4*i-3]=x;lsh[4*i-2]=y;
        lsh[4*i-1]=x-1;lsh[4*i]=y+1;
    }
    sort(lsh+1,lsh+4*n+1);
    ls[cc=1]=lsh[1];
    for(int i=2;i<=4*n;i++)
        if(lsh[i]!=lsh[i-1])ls[++cc]=lsh[i];
    for(int i=1;i<=n;i++)
    {
        a[i][0]=lower_bound(ls+1,ls+cc+1,a[i][0])-ls;
        a[i][1]=lower_bound(ls+1,ls+cc+1,a[i][1])-ls;
        s[a[i][0]]++;s[a[i][1]+1]--;
        g[a[i][1]].pb({a[i][0],i});
    }
    //for(int i=1;i<=cc;i++)sort(g[i].begin(),g[i].end());
    s[0]=0;
    for(int i=1;i<=cc;i++)s[i]+=s[i-1];
    int l=1,r;
    while(l<=cc)
    {
        while(l<=cc && s[l]<=1)l++;
        if(l>cc)break;
        r=l;
        while(r<=cc && s[r]>1)r++;
        r--;
        for(int i=l;i<=r;i++)
            for(node p : g[i])
                if(p.pos>=l)ans.pb(p.lb);
        l=r+1;
    }
    if(ans.size()==0)printf("-1\n");
    else printf("%d\n",ans[0]);
    return 0;
}