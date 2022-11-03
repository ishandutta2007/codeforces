#include <bits/stdc++.h>
using namespace std;
const int maxn=1000005;
bool vis[maxn];
int n,nok[maxn];
int main()
{
    int T,i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&j,&n);
        for(i=1;i<=n;i++) vis[i]=0,nok[i]=0;
        while(j--) scanf("%d",&i),vis[i]=1;
        for(i=1;i<=n;i++)
            if(vis[i])
                for(j=1;j*i<=n;j++)
                    if(!vis[j])
                        nok[i*j]++,nok[min(n+1,i*(j+1))]--;
        for(i=2;i<=n;i++) nok[i]+=nok[i-1];
        for(i=1;i<=n;i++)
            if(vis[i] && nok[i])
                break;
        printf("%s\n",(i>n)?"Yes":"No");
    }
    return 0;
}