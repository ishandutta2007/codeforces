#include <bits/stdc++.h>
#define N 205
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T;
int n,m;
char s[N][N];
int main()
{
        //freopen("ex1.in","r",stdin);
    T=read();
    while(T--){
        int ans=0;
        n=read(),m=read();
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);

        if(n==1 && m==1){
            puts("0");
            continue ;
        }
        if(n==1){
            for(int i=1;i<=m-1;i++)
            if(s[1][i]!='R') ans++;
            printf("%d\n",ans);
            continue ;
        }
        if(m==1){
            for(int i=1;i<=n-1;i++)
            if(s[i][1]!='D') ans++;
            printf("%d\n",ans);
            continue ;
        }

        for(int i=1;i<=n-1;i++) {
            if(s[i][m]!='D') ans++;
        }
        for(int i=1;i<=m-1;i++){
            if(s[n][i]!='R') ans++;
        }
        printf("%d\n",ans);

    }
}