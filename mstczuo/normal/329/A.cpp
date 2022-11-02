# include <iostream>
# include <cstdio>
using namespace std;

char a[120][120];
int c[120],d[120];
int main()
{
    int n;scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%s", a[i]+1);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(a[i][j]=='.')c[i]++,d[j]++;
    bool f1 = true, f2 = true;
    for(int i=1; i<=n; i++) if(!c[i]) f1=false;
    for(int i=1; i<=n; i++) if(!d[i]) f2=false;
    if(!f1&&!f2) {printf("-1\n"); return 0;}
    if(f1){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(a[i][j]=='.'){
                    printf("%d %d\n",i,j);
                    break;
                }
    }else{
        for(int j=1; j<=n; j++)
            for(int i=1; i<=n; i++)
                if(a[i][j]=='.'){
                    printf("%d %d\n",i,j);
                    break;
                }
    }
}