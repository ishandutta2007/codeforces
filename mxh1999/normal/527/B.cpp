#include<bits/stdc++.h>
using namespace std;

#define maxn 200010
char s[maxn],t[maxn];
int a[26][26];
int n;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        char ch=getchar();
        while (ch>'z' || ch<'a')    ch=getchar();
        s[i]=ch;
    }
    for (int i=1;i<=n;i++)
    {
        char ch=getchar();
        while (ch>'z' || ch<'a')    ch=getchar();
        t[i]=ch;
    }
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        if (s[i]!=t[i]) ans++,a[s[i]-'a'][t[i]-'a']=i;
    }
    for (int i=0;i<26;i++)
        for (int j=0;j<26;j++)
        if (i!=j)
        if (a[i][j] && a[j][i])
        {
            ans-=2;
            printf("%d\n",ans);
            printf("%d %d\n",a[i][j],a[j][i]);
            return 0;
        }
    for (int i=0;i<26;i++)
        for (int j=0;j<26;j++)
        if (i!=j && a[i][j])
        {
            int pos=-1;
            for (int k=0;k<26;k++)
            if (a[j][k])    {pos=k;break;}
            if (pos!=-1)
            {
                ans-=1;
                printf("%d\n",ans);
                printf("%d %d\n",a[i][j],a[j][pos]);
                return 0;
            }
        }
    printf("%d\n",ans);
    printf("-1 -1\n");
    return 0;
        
}