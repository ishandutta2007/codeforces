// 
//  
// 
//  
//   
#include<bits/stdc++.h>
using namespace std;
int task,n,k,q,a[15][100005];
namespace subtask1
{
    int z[100505][105],cnt;
    inline void cmx(int id,int x,int y) {for(int i=1;i<=n;i++) z[id][i]=max(z[x][i],z[y][i]);}
    inline void cmn(int id,int x,int y) {for(int i=1;i<=n;i++) z[id][i]=min(z[x][i],z[y][i]);}
    inline void main()
    {
        for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) z[i][j]=a[i][j];
        cnt=k;
        for(int i=1,f,x,y;i<=q;i++)
        {
            scanf("%d%d%d",&f,&x,&y);
            if(f==1) cmx(++cnt,x,y);
            if(f==2) cmn(++cnt,x,y);
            if(f==3) printf("%d\n",z[x][y]);
        }
    }
}
namespace subtask3
{
    int mx[100505],cnt;
    inline int query(int id,int w)
    {
        int maxn=0;
        for(int i=1;i<=k;i++) if((mx[id]>>(i-1))&1) maxn=max(maxn,a[i][w]);
        return maxn;
    }
    inline void main()
    {
        cnt=k;
        for(int i=1;i<=k;i++) mx[i]=(1<<(i-1));
        for(int i=1,x,y,f;i<=q;i++)
        {
            scanf("%d%d%d",&f,&x,&y);
            if(f==1) mx[++cnt]=mx[x]|mx[y];
            else printf("%d\n",query(x,y));
        }
    }
}
namespace subtask7
{
    bitset<((1<<12)+1)>f[100005];struct node{int x,id;}g[100005][15];
    int cnt=0;
    inline bool cmp(node a,node b) {return a.x>b.x||(a.x==b.x&&a.id<b.id);}
    inline int query(int x,int y)
    {
        int st=0;
        for(int i=1;i<=k;i++)
        {
            st|=(1<<(g[y][i].id-1));
            if(f[x][st]) return g[y][i].x;
        }
        return -1;
    }
    inline void main()
    {
        for(int i=1;i<=k;i++) for(int j=0;j<=(1<<k)-1;j++) f[i][j]=((j>>(i-1))&1);
        for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) g[j][i]=(node){a[i][j],i};
        for(int i=1;i<=n;i++) sort(g[i]+1,g[i]+k+1,cmp);
        cnt=k;
        for(int x,y,op;q--;)
        {
            scanf("%d%d%d",&op,&x,&y);
            if(op==1) f[++cnt]=f[x]|f[y];
            if(op==2) f[++cnt]=f[x]&f[y];
            if(op==3) printf("%d\n",query(x,y));
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&k,&q),task=1;
    for(int i=1;i<=k;i++) for(int j=1;j<=n;j++) scanf("%d",&a[i][j]),task&=(a[i][j]<=2);
    // if(n<=100) subtask1::main();else subtask3::main();
    subtask7::main();
    return 0;
}