#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
const int INF=1000000000;
int K,n,c[200010],pre[200010],res=INF;
int main()
{
    scanf("%d%d",&K,&n);
    for(int i=1,x;i<=n;i++) scanf("%d",&x),c[x]++;
    for(int i=1;i<=K;i++)
        if(c[i]) pre[i]=i;
        else pre[i]=pre[i-1];
    for(int i=0;i<K;i++)
    {
        c[i]++;
        int o=K,now=max(pre[o],i);
        while(now)
        {
            int p=c[now];
            int t=min(p,o/now);
            o-=now*t;
            int nt=min(pre[o],pre[now-1]);
            if(nt<i&&now>i) now=i;
            else now=min(pre[o],pre[now-1]);
        }
        if(o!=0) res=min(res,i);
        c[i]--;
    }
    if(res==INF) puts("Greed is good");
    else printf("%d\n",res);
    return 0;
}