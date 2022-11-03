#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,d[maxn],id[maxn<<1],tot;
inline bool cmp(int x,int y) { return d[x/2]>d[y/2]; }
int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&d[i]),id[i]=i*2+1;
    sort(id,id+n,cmp);
    for(i=1;i<n;i++) printf("%d %d\n",id[i-1],id[i]);
    tot=n;
    for(i=0;i<n;i++)
    {
        printf("%d %d\n",id[i]+1,id[i+d[id[i]/2]-1]);
        if(i+d[id[i]/2]>=tot) id[tot++]=id[i]+1;
    }
    return 0;
}