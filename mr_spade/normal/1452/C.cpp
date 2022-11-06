#include<cstdio>
const int N=5e6+5;
char s[N];
inline void solve()
{
    int a=0,b=0,ans=0;
    register int i;
    scanf("%s",s);
    for(i=0;s[i];i++)
        if(s[i]=='(')
            a++;
        else if(s[i]=='[')
            b++;
        else if(s[i]==')')
        {
            if(a)
                a--,ans++;
        }
        else
        {
            if(b)
                b--,ans++;
        }
    printf("%d\n",ans);
    return;
}
signed main()
{
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}