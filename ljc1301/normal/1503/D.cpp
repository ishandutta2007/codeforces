#include <bits/stdc++.h>
using namespace std;
// 1~9
// 1 => 1 8 9 => 1 2 8 9 ...
// 7 => 7 4 3 => 7 ? 4 3 ...
const int maxn=200005;
int n,ans,a[maxn],b[maxn],id[2][maxn],it[2],l1,r1,l2,r2,tot,cur;
bool vis[maxn];
inline bool cmp1(int x,int y) { return min(a[x],b[x])<min(a[y],b[y]); }
inline bool cmp2(int x,int y) { return max(a[x],b[x])>max(a[y],b[y]); }
inline int get(int k)
{
    for(;it[k]<n && vis[id[k][it[k]]];it[k]++);
    return (it[k]==n)?n:id[k][it[k]];
}
inline bool determine(int i)
{
    // printf("? %d %d\n",a[i],b[i]);
    if((a[i]<l1 || a[i]>r1 || b[i]<l2 || b[i]>r2) && (b[i]<l1 || b[i]>r1 || a[i]<l2 || a[i]>r2))
        throw -1;
    if(a[i]<l1 || a[i]>r1 || b[i]<l2 || b[i]>r2)
    {
        cur++;
        if(a[i]<b[i]) r1=b[i],l2=a[i];
        else r2=a[i],l1=b[i];
        // printf("%d %d\n",b[i],a[i]);
        return true;
    }
    if(b[i]<l1 || b[i]>r1 || a[i]<l2 || a[i]>r2)
    {
        if(a[i]<b[i]) r2=b[i],l1=a[i];
        else r1=a[i],l2=b[i];
        // printf("%d %d\n",a[i],b[i]);
        return true;
    }
    return false;
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d%d",&a[i],&b[i]),id[0][i]=id[1][i]=i,vis[i]=0;
    sort(id[0],id[0]+n,cmp1),sort(id[1],id[1]+n,cmp2);
    // for(i=0;i<n;i++) printf("%d ",id[0][i]); printf("\n");
    // for(i=0;i<n;i++) printf("%d ",id[1][i]); printf("\n");
    try
    {
        for(it[0]=it[1]=0,ans=0;(i=get(0))<n;ans+=min(cur,tot-cur))
        {
            tot=1,l2=0,r1=2*n+1;
            l1=min(a[i],b[i]),r2=max(a[i],b[i]);
            // printf("%d %d\n",min(a[i],b[i]),max(a[i],b[i]));
            cur=a[i]>b[i],vis[i]=1,it[0]++;
            for(;get(0)<n;)
            {
                if(determine(get(0))) { vis[id[0][it[0]++]]=1,tot++; continue; }
                if(determine(get(1))) { vis[id[1][it[1]++]]=1,tot++; continue; }
                break;
            }
            // printf("-------\n");
        }
        printf("%d\n",ans);
    }
    catch(...) { printf("-1\n"); }
    return 0;
}