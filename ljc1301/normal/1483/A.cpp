#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
vector<int> ttt[maxn];
int n,m,cnt[maxn],ans[maxn];
int main()
{
    int T,i,s,k,x;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m),s=(m+1)>>1;
        for(i=1;i<=n;i++) cnt[i]=0;
        for(i=0;i<m;i++)
        {
            ttt[i].clear();
            scanf("%d",&k);
            while(k--) scanf("%d",&x),ttt[i].push_back(x);
            cnt[ttt[i][0]]++,ans[i]=ttt[i][0];
        }
        for(i=2,k=1;i<=n;i++)
            if(cnt[i]>cnt[k])
                k=i;
        for(i=0;cnt[k]>s && i<m;i++)
            if(ans[i]==k && (int)ttt[i].size()>=2)
                cnt[k]--,ans[i]=ttt[i][1];
        if(/*i>=m*/cnt[k]>s) printf("NO\n");
        else
        {
            printf("YES\n");
            for(i=0;i<m;i++)
                printf("%d ",ans[i]);
            printf("\n");
        }
    }
    return 0;
}