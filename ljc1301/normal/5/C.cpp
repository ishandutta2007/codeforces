#include <cstdio>
const int maxn=1000005;
char s[maxn];
int top,sta[maxn],ans,cnt,f[maxn];
int main()
{
    int i;
    scanf("%s",s+1);
    top=0; ans=0; cnt=1;
    f[0]=0;
    for(i=1;s[i];i++)
        if(s[i]=='(')
            sta[top++]=i,f[i]=0;
        else if(top<=0)
            f[i]=0;
        else
        {
            top--;
            f[i]=f[sta[top]-1]+i-sta[top]+1;
            if(f[i]>ans)
                ans=f[i],cnt=0;
            if(f[i]==ans)
                cnt++;
        }
    printf("%d %d\n",ans,cnt);
    return 0;
}