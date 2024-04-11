#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int MAXN=300010;
pair<int,int> ans[MAXN];
int n,a[MAXN],s1[MAXN],s2[MAXN],pre1[MAXN],pre2[MAXN],tot1,tot2,cnt;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        if(a[i]==1) s1[++tot1]=i;
        else s2[++tot2]=i;
    for(int i=1;i<=n;i++)
    {
        pre1[i]=pre1[i-1];
        pre2[i]=pre2[i-1];
        if(a[i]==1) pre1[i]++;
        else pre2[i]++;
    }
    for(int T=1;T<=n;T++)
    {
        int sub=0,con,w1=0,w2=0,w=0,who=0,nw=0;
        while(1)
        {
            int x=pre1[sub];
            x+=T;
            con=s1[x],w1++,nw=1;
            if(con-sub-T>=T||con==0)
            {
                x=pre2[sub];
                x+=T;
                con=s2[x],w1--,w2++,nw=2;
            }
            sub=con;
            if(w1>w) w=w1,who=1;
            else if(w2>w) w=w2,who=2;
            if(con==n&&nw==who) {ans[++cnt]=make_pair(max(w1,w2),T);break;}
            else if(con==0) break;
        }
    }
    sort(ans+1,ans+cnt+1);
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++) printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}