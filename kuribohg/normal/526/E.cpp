#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
#define next next2
using namespace std;
typedef long long LL;
const int MAXN=3000010;
const int INF=1000000000;
int n,Q,next[MAXN],ans,tot;
pair<int,int> P[MAXN];
LL a[MAXN],s[MAXN],limit;
int main()
{
    scanf("%d%d",&n,&Q);
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    for(int i=n+1;i<=n+n;i++) a[i]=a[i-n];
    for(int i=1;i<=n+n;i++) s[i]=s[i-1]+a[i];
    while(Q--)
    {
        scanf("%I64d",&limit);
        int R=0;
        for(int i=1;i<=n+n;i++)
        {
            R=max(R,i);
            while(R<=n+n&&s[R]-s[i-1]<=limit) R++;
            next[i]=R;
        }
        next[n+n+1]=n+n+1;
        int T=0,x=1,S=1;
        ans=INF;
        tot=0;
        while(x<n+1)
        {
            P[++tot]=make_pair(x,next[x]-1);
            x=next[x],T++;
        }
        ans=min(ans,T);
        int Len=INF,sub=0;
        for(int i=1;i<tot;i++)
            if(P[i].second-P[i].first<Len) sub=i,Len=P[i].second-P[i].first;
        for(int i=P[sub].first;i<=P[sub].second+1;i++)
        {
            T=0,x=i;
            if(x>n+n) continue;
            if(x>n) x-=n;
            int tmp=x;
            while(x<tmp+n)
            {
                x=next[x];
                T++;
                if(T>=ans) break;
            }
            ans=min(ans,T);
        }
        printf("%d\n",ans);
    }
    return 0;
}