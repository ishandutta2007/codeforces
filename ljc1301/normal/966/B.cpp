#include <bits/stdc++.h>
using namespace std;
const int maxn=300005;
#define x1 dsfgjhdsvjh
#define x2 gvjxchugvwe
int n,x1,x2,c[maxn],id[maxn],suf[maxn],pre[maxn];
inline int ceil_div(int a,int b) { return (a+b-1)/b; }
inline bool cmp(int a,int b) { return c[a]>c[b]; }
int main()
{
    int i,j,a,b;
    scanf("%d%d%d",&n,&x1,&x2);
    for(i=1;i<=n;i++) scanf("%d",&c[i]),id[i-1]=i;
    sort(id,id+n,cmp);
    for(i=n-1,suf[n]=0x80000000;i>=0;i--)
        suf[i]=max(suf[i+1],i-ceil_div(x2,c[id[i]])+1);
    for(i=1,pre[0]=-ceil_div(x2,c[id[0]])+1;i<n;i++)
        pre[i]=max(pre[i-1],i-ceil_div(x2,c[id[i]])+1);
    for(i=0;i<n;i++)
        if(i-ceil_div(x1,c[id[i]])+1>=0)
        {
            if(i-ceil_div(x1,c[id[i]])>=0 && pre[i-ceil_div(x1,c[id[i]])]>=0)
            {
                printf("Yes\n");
                for(a=0;a<n;a++)
                    if(a-ceil_div(x2,c[id[a]])+1>=0)
                        break;
                printf("%d %d\n",ceil_div(x1,c[id[i]]),a+1);
                for(j=i-ceil_div(x1,c[id[i]])+1;j<=i;j++)
                    printf("%d ",id[j]);
                printf("\n");
                for(j=0;j<=a;j++) printf("%d ",id[j]);
                printf("\n");
                return 0;
            }
            if(suf[i+1]>=ceil_div(x1,c[id[i]]))
            {
                printf("Yes\n");
                for(a=i+1;a<n;a++)
                    if(a-ceil_div(x2,c[id[a]])+1>=ceil_div(x1,c[id[i]]))
                        break;
                printf("%d %d\n",ceil_div(x1,c[id[i]]),a+1-ceil_div(x1,c[id[i]]));
                for(j=i-ceil_div(x1,c[id[i]])+1;j<=i;j++)
                    printf("%d ",id[j]);
                printf("\n");
                for(j=0;j<i-ceil_div(x1,c[id[i]])+1;j++) printf("%d ",id[j]);
                for(j=i+1;j<=a;j++) printf("%d ",id[j]);
                printf("\n");
                return 0;
            }
        }
    printf("No\n");
    return 0;
}