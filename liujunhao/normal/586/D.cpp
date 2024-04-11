#include<cstdio>
#include<cstring>
#define MAXN 100
int n,k,T;
char s[4][MAXN*4+10];
bool f[2][4];
int main()
{
    int p,i,x;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(i=1;i<=3;i++)
            scanf("%s",s[i]+1);
        for(i=n+1;i<=3*MAXN;i++)
            s[1][i]=s[2][i]=s[3][i]='.';
        x=1;
        memset(f,0,sizeof f);
        for(i=1;i<=3;i++)
            if(s[i][1]=='s')
                break;
        p=0;
        f[p][i]=1;
        for(i=1;i<=n&&x<=n;i++){
            x++,p^=1;
            f[p][1]=s[1][x]=='.'&&(f[p^1][1]|(s[2][x]=='.'&&f[p^1][2]));
            f[p][2]=s[2][x]=='.'&&(f[p^1][2]|(s[1][x]=='.'&&f[p^1][1])|(s[3][x]=='.'&&f[p^1][3]));
            f[p][3]=s[3][x]=='.'&&(f[p^1][3]|(s[2][x]=='.'&&f[p^1][2]));
            x++;
            f[p][1]&=(s[1][x]=='.'); 
            f[p][2]&=(s[2][x]=='.');
            f[p][3]&=(s[3][x]=='.');
            x++;
            f[p][1]&=(s[1][x]=='.');
            f[p][2]&=(s[2][x]=='.');
            f[p][3]&=(s[3][x]=='.');
        }
        if(f[p][1]||f[p][2]||f[p][3])
            puts("YES");
        else
            puts("NO");
    }
}