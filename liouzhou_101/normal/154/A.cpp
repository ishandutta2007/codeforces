#include<cstdio>
#include<cstring>

const int MaxN=100010;

int n,k;
char s[MaxN];
int F[MaxN][30];
int v[255];

int min(int a,int b)
{
    return (a<b)?a:b;
}

int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    scanf("%d",&k);
    for (int i=1;i<=k;++i)
    {
        char p[4];
        scanf("%s",p);
        v[p[0]]=p[1];
        v[p[1]]=p[0];
    }
    F[0][0]=0;
    for (int i=1;i<=n;++i)
    {
        for (int j=0;j<=26;++j)
            F[i][j]=1000000000;
        F[i][s[i]-'a'+1]=F[i-1][0];
        F[i][0]=F[i-1][0]+1;
        for (int j=1;j<=26;++j)
        {
            F[i][j]=min(F[i][j],F[i-1][j]+1);
            if (v[s[i]]!=j+'a'-1)
                F[i][s[i]-'a'+1]=min(F[i][s[i]-'a'+1],F[i-1][j]);
        }
    }
    int ans=1000000000;
    for (int i=0;i<=26;++i)
        ans=min(ans,F[n][i]);
    printf("%d\n",ans);
    return 0;
}