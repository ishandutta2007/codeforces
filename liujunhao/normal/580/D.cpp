#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 18
long long n,m,a[MAXN+2],mat[MAXN+2][MAXN+2],f[1<<MAXN][MAXN+2],ans,k;
void Read(long long &x){
    char c;
    while(c=getchar(),c!=EOF)
        if(c>='0'&&c<='9'){
            x=c-'0';
            while(c=getchar(),c>='0'&&c<='9')
                x=x*10+c-'0';
            ungetc(c,stdin);
            return;
        }
}
void read(){
    long long i,u,v,wt;
    Read(n),Read(m),Read(k);
    for(i=1;i<=n;i++)
        Read(a[i]);
    for(i=1;i<=k;i++){
        Read(u),Read(v),Read(wt);
        mat[u][v]=wt;
    }
}
inline long long lowbit(long long x){
    return x&-x;
}
void dp(){
    long long s,j,k,t,tmp,cnt;
    t=1<<n;
    for(j=1;j<=n;j++)
        f[1<<(j-1)][j]=a[j];
    for(s=0;s<t;s++){
        tmp=s;
        cnt=0;
        while(tmp){
            tmp-=lowbit(tmp);
            cnt++;
        }
        for(j=1;j<=n;j++){
            if(!(s&(1<<(j-1))))
                continue;
            for(k=1;k<=n;k++)
                if(s&(1<<(k-1)))
                    f[s][j]=max(f[s^(1<<(j-1))][k]+a[j]+mat[k][j],f[s][j]);
                if(cnt==m)
                    ans=max(f[s][j],ans);
            }
    }
}
int main()
{
    read();
    dp();
    printf("%I64d\n",ans);
}