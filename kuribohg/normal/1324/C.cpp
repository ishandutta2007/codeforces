#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n;
char s[200010];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s+1);
        n=strlen(s+1);
        s[0]='R',s[n+1]='R';
        int ans=1;
        for(int i=0;i<=n;i++)
            if(s[i]=='R')
            {
                int r=i+1;
                while(s[r]=='L') r++;
                ans=max(ans,r-i);
            }
        printf("%d\n",ans);
    }
    return 0;
}