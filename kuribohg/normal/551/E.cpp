#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<utility>
using namespace std;
typedef long long LL;
typedef pair<LL,int> PLI;
const int MAXN=500010;
const int MAXK=1010;
const int INF=1000000000;
int n,Q,K,tot,L[MAXK],R[MAXK];
LL delta[MAXK];
PLI a[MAXN];
int main()
{
    scanf("%d%d",&n,&Q);
    for(int i=0;i<n;i++) scanf("%I64d",&a[i].first),a[i].second=i;
    K=(int)sqrt(n)+5;
    tot=n/K;if(n%K) tot++;
    for(int i=0;i<tot;i++)
    {
        L[i]=i*K,R[i]=min((i+1)*K-1,n-1);
        sort(a+L[i],a+R[i]+1);
    }
    while(Q--)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            int l,r;
            LL x;
            scanf("%d%d%I64d",&l,&r,&x);
            l--,r--;
            int lk=l/K,rk=r/K;
            if(lk==rk)
            {
                for(int i=L[lk];i<=R[lk];i++)
                    if(a[i].second>=l&&a[i].second<=r) a[i].first+=x;
                sort(a+L[lk],a+R[lk]+1);
            }
            else
            {
                for(int i=lk+1;i<=rk-1;i++) delta[i]+=x;
                for(int i=L[lk];i<=R[lk];i++)
                    if(a[i].second>=l&&a[i].second<=r) a[i].first+=x;
                for(int i=L[rk];i<=R[rk];i++)
                    if(a[i].second>=l&&a[i].second<=r) a[i].first+=x;
                sort(a+L[lk],a+R[lk]+1);
                sort(a+L[rk],a+R[rk]+1);
            }
        }
        else
        {
            LL x;
            int minsub=INF,maxsub=-INF;
            scanf("%I64d",&x);
            for(int i=0;i<tot;i++)
            {
                PLI tmp=make_pair(x-delta[i],0);
                int sub=lower_bound(a+L[i],a+R[i]+1,tmp)-a;
                if(sub>R[i]) continue;
                if(a[sub].first==x-delta[i]) minsub=min(minsub,a[sub].second),maxsub=max(maxsub,a[sub].second);
            }
            for(int i=0;i<tot;i++)
            {
                PLI tmp=make_pair(x-delta[i]+1,0);
                int sub=lower_bound(a+L[i],a+R[i]+1,tmp)-a;
                sub--;
                if(sub<L[i]) continue;
                if(a[sub].first==x-delta[i]) minsub=min(minsub,a[sub].second),maxsub=max(maxsub,a[sub].second);
            }
            if(minsub==INF) puts("-1");
            else printf("%d\n",maxsub-minsub);
        }
    }
    return 0;
}