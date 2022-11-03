#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxk=100005;
const int maxn=100005;
struct node
{
    int a,tp,i,id; ll b;
    inline bool operator <(const node &x) const
    {
        return a*x.b>x.a*b;
    }
}p[maxn];
ll a[maxk];
int n,m,k,t[maxn],id[maxn],tot;
// set <=> add
inline bool cmp(int x,int y) { return p[x].tp<p[y].tp; }
int main()
{
    int i;
    scanf("%d%d%d",&k,&n,&m);
    for(i=1;i<=k;i++) scanf("%lld",&a[i]);
    for(i=1;i<=n;i++)
        scanf("%d%d%d",&p[i].tp,&p[i].i,&p[i].a),p[i].b=1,p[i].id=i;
    for(i=1;i<=k;i++) t[i]=-1;
    for(i=1;i<=n;i++)
        if(p[i].tp==1 && p[i].a>a[p[i].i] && (t[p[i].i]==-1 || p[i].a-a[p[i].i]>p[t[p[i].i]].a))
            t[p[i].i]=i,p[i].a-=a[p[i].i];
    for(i=1;i<=n;i++)
        if(p[i].tp==1 && t[p[i].i]!=i)
            p[i].tp=0xdead;
    sort(p+1,p+1+n);
    for(i=1;i<=n;i++)
        if(p[i].tp<=2)
            p[i].b=a[p[i].i],a[p[i].i]+=p[i].a;
        else if(p[i].tp==3)
            p[i].a--;
    sort(p+1,p+1+n);
    for(i=1,tot=0;m && i<=n;i++)
        if(p[i].tp<=3)
            m--,id[tot++]=i;
    sort(id,id+tot,cmp);
    printf("%d\n",tot);
    for(i=0;i<tot;i++)
        printf("%d ",p[id[i]].id);
    printf("\n");
    return 0;
}