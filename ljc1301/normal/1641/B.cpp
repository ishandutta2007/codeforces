#include <bits/stdc++.h>
using namespace std;
const int maxn=505;
const int maxans=maxn*maxn*2;
int n,m,tot,a[maxn],/*pre[maxn],ne[maxn],*/d,t[maxans],q,pos[maxans],xxx[maxans],b[maxn];
map<int,int> s;
int main()
{
    int T,i,cnt,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(s.clear(),tot=0,i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            // if(s.count(a[i])) /*pre[i]=s[a[i]],*/s.erase(a[i])/*,ne[pre[i]]=i*/,ne[i]=-1,a[i]=a[pre[i]];
            if(s.count(a[i])) j=a[i],a[i]=a[s[a[i]]],s.erase(j);
            else s[a[i]]=i,/*pre[i]=-1,*/b[tot]=a[i],a[i]=tot++;
        }
        if(!s.empty()) { printf("-1\n"); continue; }
        d=q=0;
        // for(i=0;i<n;i++) printf("%d ",a[i]); printf("\n");
        for(m=n;m;m-=2)
        {
            for(i=0;i<m;i++)
                if(a[i]==a[m-1])
                    break;
            t[d++]=m-1-i;
            for(j=0;j<m-2-i;j++)
                pos[q]=i+j,xxx[q++]=b[a[m-2-j]];
            for(j=i;j<m-2;j++) a[j]=a[j+1];
            reverse(a+i,a+m-2);
        }
        printf("%d\n",q);
        for(i=0;i<q;i++) printf("%d %d\n",pos[i],xxx[i]);
        printf("%d\n",d);
        for(i=d-1;i>=0;i--) printf("%d%c",t[i]<<1,i?' ':'\n');
    }
    return 0;
}