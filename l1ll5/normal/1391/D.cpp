#include <bits/stdc++.h>
#define N 1000005
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
int n,m,mx;
char s[4][N];
int f[N][10];

int dis(int a,int b){
    int ret=0;
    for(int i=0;i<n;i++){
        int ta=(a>>i)&1;
        int tb=(b>>i)&1;
        if(ta!=tb) ret++;
    }
    return ret;
}

int sta(int x){
    int ret=0;
    ret+= (s[1][x]-'0') ;
    ret+= (s[2][x]-'0')*2 ;
    ret+= (s[3][x]-'0')*4 ;
    return ret;
}


int main()
{
//    freopen("ex1.in","r",stdin);
    n=read(),m=read();
    if(n>=4 && m>=4){
        puts("-1");
        return 0;
    }

    if(n==1){
        puts("0");
        return 0;
    }

    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);

    mx=(1<<n)-1;

    memset(f,0x3f,sizeof(f));
    for(int i=0;i<=mx;i++) f[1][i]=dis(sta(1),i);

    for(int i=2;i<=m;i++){
        for(int j=0;j<=mx;j++){
            for(int k=0;k<=mx;k++){

                bool ok=1;
                int cnt1=0;
                if(n==2){
                    cnt1 += (j&1) ;
                    cnt1 += (j>>1) & 1;
                    cnt1 += (k&1) ;
                    cnt1 += (k>>1) & 1;

                    if(cnt1%2==0) ok=0;
                }else{
                    //n==3
                    cnt1 += (j&1) ;
                    cnt1 += (j>>1) & 1;
                    cnt1 += (k&1) ;
                    cnt1 += (k>>1) & 1;

                    if(cnt1%2==0) ok=0;

                    cnt1=0;

                    cnt1 += (j>>1) & 1;
                    cnt1 += (j>>2) & 1;
                    cnt1 += (k>>1) & 1;
                    cnt1 += (k>>2) & 1;

                    if(cnt1%2==0) ok=0;

                }

                if(ok){
                //    cerr<<i<<' '<<j<<' '<<k<<' '<<dis(sta(i),k)<<' '<<f[i-1][j]<<endl;
                    f[i][k]=min(f[i-1][j]+dis(sta(i),k),f[i][k]);
                }

            }
        }
    }
    int ans=1000000000;
    for(int j=0;j<=mx;j++) ans=min(ans,f[m][j]);

    if(ans>n*m) ans=-1;
    printf("%d\n",ans);
}