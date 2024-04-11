# include <iostream>
# include <cstdio>
using namespace std;
const int MAXN = 2010;
char a[MAXN][MAXN];
int s[MAXN][MAXN];
int sum(int x1,int y1,int x2,int y2){
    return (s[x1][y1]+s[x2][y2]-s[x1][y2]-s[x2][y1]);
}

int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(a[i][j]=='w');
    int li=n+1, ri=0, lj=m+1, rj=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]=='w')
                li = min(li, i), ri = max(ri, i),
                lj = min(lj, j), rj = max(rj, j);
    int len = max(ri-li,rj-lj)+1;
    if(len==1){
        for(int i=1;i<=n;i++)printf("%s\n",a[i]+1);
        return 0;
    }
    int si = 0, sj = 0;
    for(int i=len;i<=n;i++)
        for(int j=len;j<=m;j++)
            if(sum(i-len+1,j-len+1,i-1,j-1)==0)
                if(sum(i-len,j-len,i,j)==s[n][m])
                    si = i, sj = j;
    if(si && sj) {
        for(int i=si-len+1; i<=si; i++)
            for(int j=sj-len+1; j<=sj; j++)
                if(a[i][j]=='.') a[i][j]='+';
        for(int i=si-len+2; i<si; i++)
            for(int j=sj-len+2; j<sj; j++)
                a[i][j]='.';
        for(int i=1;i<=n;i++)printf("%s\n",a[i]+1);
    } else return cout << -1 << endl, 0;
}