#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,pos[maxn];
char s[maxn],ans[2][maxn];
inline bool check(int k)
{
    int i,cur=0;
    for(i=0;i<n;i++)
        if(ans[k][i]=='(') cur++;
        else if((--cur)<0) return false;
    return cur==0;
}
int main()
{
    int T,i,cnt,cur;
    scanf("%d",&T);
    while(T--)
    {
        // tot=0 same: +a,+a; diff: +b,-b ->a=b=0
        scanf("%d%s",&n,s),ans[0][n]=ans[1][n]='\0';
        cnt=0;
        for(i=0;i<n;i++)
            cnt+=s[i]-'0';
        if(cnt%2) { printf("NO\n"); continue; }
        for(i=0,cur=0;i<n;i++)
            if(s[i]=='1')
                ans[0][i]=ans[1][i]=(cur<(cnt/2))?'(':')',cur++;
        for(i=0,cur=0;i<n;i++)
            if(s[i]=='0')
                ans[cur&1][i]='(',ans[(cur^1)&1][i]=')',cur++;
        if(!check(0) || !check(1)) printf("NO\n");
        else printf("YES\n%s\n%s\n",ans[0],ans[1]);
    }
    return 0;
}