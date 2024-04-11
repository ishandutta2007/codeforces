# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
int a[4001][4001],s[4001][4001],q[4001];
int n,m, F1[4001],F2[4001], *f,*g;
char c[10000];

bool ok(int x,int y,int t)
{ 
    return g[x]+s[x+1][t]<g[y]+s[y+1][t]; 
}

int slope(int x,int y)
{
    int L=y, R=n+1, M;
    while(R-L>1)
        ok(x,y,M=(L+R)>>1)?L=M:R=M;
    return L;
}

int main()
{
    gets(c); sscanf(c,"%d%d",&n,&m);
    rep(i,n) {
        gets(c);
        rep(j,n)
            a[i][j]=c[j*2-2]-'0';
    }
    
    memset(s,0,sizeof(s));
    rep(j,n) rep(i,n-j) s[i][i+j] = s[i+j][i] = \
        s[i+1][i+j]+s[i][i+j-1]-s[i+1][i+j-1]+a[i][i+j];

    f = F1, g = F2; int h, t;
    rep(i,n) g[i] = s[1][i];
    for(int k=1;k<m;k++,swap(f,g))
    {
        q[h=t=1]=k;
        for(int i=k+1;i<=n;i++){
            while (h<t && slope(q[h],q[h+1])<i) h++;
            f[i] = g[q[h]] + s[q[h]+1][i];
            while (h<t && slope(q[t],i)<=slope(q[t-1],q[t])) t--;
            q[++t] = i;
        }
    }
    
    printf("%d\n",g[n]);
    return 0;
}