#include<cstdio>
#include<cstring>

const int MaxN=110;
const int MOD=1000000007;

int n;
char s[MaxN];
int F[MaxN][2600];

int main()
{
    F[0][0]=1;
    for (int i=0;i<100;++i)
        for (int j=0;j<=2500;++j)
            if (F[i][j])
                for (int k=0;k<26;++k)
                    F[i+1][j+k]=(F[i+1][j+k]+F[i][j])%MOD;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s+1);
        n=strlen(s+1);
        int tmp=0;
        for (int i=1;i<=n;++i)
            tmp+=(s[i]-'a');
        printf("%d\n",(F[n][tmp]-1+MOD)%MOD);
    }
    return 0;
}