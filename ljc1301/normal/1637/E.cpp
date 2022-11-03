#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=300005;
int n,t,s,a[maxn],c[maxn];
ll b[maxn],x[maxn];
// pair<ll,int> maxx[maxn];
vector<int> v[maxn],u[maxn];
bool vis[maxn];
int main()
{
    int T,i,j,k,l,m;
    ll ans;
    vector<int>::iterator it;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++) scanf("%d",&a[i]),b[i]=a[i];
        sort(b,b+n),t=unique(b,b+n)-b;
        for(i=0;i<t;i++) c[i]=0,v[i].clear(),v[i].push_back(i);
        for(i=0;i<=n;i++) u[i].clear();
        for(i=0;i<n;i++) c[lower_bound(b,b+t,a[i])-b]++;
        while(m--)
        {
            scanf("%d%d",&i,&j);
            i=lower_bound(b,b+t,(ll)i)-b,j=lower_bound(b,b+t,(ll)j)-b;
            v[i].push_back(j),v[j].push_back(i);
        }
        for(i=0;i<t;i++) a[i]=c[i];
        sort(a,a+t),s=unique(a,a+t)-a; // t=O(sqrt(n))
        // for(i=0;i<=n;i++) maxx[i].first=-1,maxx[i].second=i;
        // maxx[n+1].first=-1;
        for(i=0;i<t;i++)
        {
            // maxx[c[i]].first=max(maxx[c[i]].first,b[i]);
            u[c[i]].push_back(i);
        }
        // sort(maxx,maxx+n+2,greater<pair<ll,int> >());
        for(i=0;i<=n;i++) sort(u[i].begin(),u[i].end(),greater<int>());
        for(i=0;i<t;i++) vis[i]=0;
        ans=-1;
        // for(i=0;i<t;i++) printf("(%lld, %d) ",b[i],c[i]); printf("\n");
        for(i=0;i<t;i++)
        {
            for(it=v[i].begin();it!=v[i].end();++it)
                vis[*it]=1;
            // for(j=0;maxx[j].first!=-1;j++)
            //     if(!vis[maxx[j].second])
            //     {
            //         // printf("! %d %d %d\n",i,maxx[j].second,maxx[j].first,j);
            //         ans=max(ans,(b[maxx[j].second]+b[i])*(c[i]+c[maxx[j].second]));
            //         break;
            //     }
            // for(k=0;k<j;k++)
            // {
            //     // printf("? %d\n",maxx[k].second);
            //     for(it=u[maxx[k].second].begin();it!=u[maxx[k].second].end();++it)
            //         if(!vis[*it])
            //         {
            //             // printf("! %d %d %lld\n",i,*it,(b[*it]+b[i])*(c[*it]+c[i]));
            //             ans=max(ans,(b[*it]+b[i])*(c[*it]+c[i]));
            //             break;
            //         }
            // }
            for(k=0;k<s;k++)
                for(it=u[a[k]].begin();it!=u[a[k]].end();++it)
                    if(!vis[*it])
                    {
                        ans=max(ans,(b[*it]+b[i])*(c[*it]+c[i]));
                        break;
                    }
            for(it=v[i].begin();it!=v[i].end();++it)
                vis[*it]=0;
        }
        printf("%lld\n",ans);
    }
    return 0;
}