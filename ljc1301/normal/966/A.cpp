#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
#define x1 asdfasjdhfj
#define x2 asfjgzxcvas
#define y1 dsdcxocxbvd
#define y2 fudgtuxcgvx
int cl,ce,l[maxn],e[maxn],v;
int main()
{
    int i,q,x1,x2,y1,y2,ans,x;
    scanf("%*d%*d%d%d%d",&cl,&ce,&v);
    for(i=0;i<cl;i++) scanf("%d",&l[i]);
    for(i=0;i<ce;i++) scanf("%d",&e[i]);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
        if(y1==y2) printf("%d\n",abs(x2-x1));
        else
        {
            ans=0x7fffffff;
            if(x1>x2) swap(x1,x2);
            if(cl)
            {
                x=lower_bound(l,l+cl,x1)-l;
                if(x!=cl && l[x]<=x2) ans=x2-x1+abs(y1-y2);
                else
                {
                    if(x!=cl) ans=min(ans,l[x]-x1+l[x]-x2+abs(y1-y2));
                    if((--x)>=0) ans=min(ans,x1-l[x]+x2-l[x]+abs(y1-y2));
                }
            }
            if(ce)
            {
                x=lower_bound(e,e+ce,x1)-e;
                if(x!=ce && e[x]<=x2) ans=x2-x1+(abs(y1-y2)-1)/v+1;
                else
                {
                    if(x!=ce) ans=min(ans,e[x]-x1+e[x]-x2+(abs(y1-y2)-1)/v+1);
                    if((--x)>=0) ans=min(ans,x1-e[x]+x2-e[x]+(abs(y1-y2)-1)/v+1);
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}