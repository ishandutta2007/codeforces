#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kcz=1000000007;
const int maxlen=4005;
char s[maxlen];
ll x[maxlen],A[maxlen],p,f[2][maxlen][2][2]; // len from begin; vp; lend 1; 0:n<A 1:n=A
int len,a,cur;
inline void init()
{
    int i,lens;
    ll c;
    lens=strlen(s);
    for(i=0;i<lens;i++) x[i]=s[lens-1-i]-'0';
    for(len=0;lens;len++)
    {
        for(i=lens-1,c=0;i>=0;i--)
            c=c*10+x[i],x[i]=c/p,c%=p;
        A[len]=c;
        for(;lens && !x[lens-1];lens--);
    }
    reverse(A,A+len+1);
}
inline ll C2(ll x) { return (x%kcz)*(x%kcz-1)/2%kcz; }
int main()
{
    int i,j;
    ll ans;
    scanf("%lld%d%s",&p,&a,s);
    init();
    // for(i=1;i<=len;i++) printf("%lld ",A[i]); printf("\n");
    cur=0,f[cur][0][0][1]=1,f[cur][0][1][0]=f[cur][0][1][1]=f[cur][0][0][0]=0;
    for(i=1;i<=len;i++/*,printf("\n")*/)
        for(cur^=1,j=0;j<=i;j++)
        {
            f[cur][j][0][0]=(j<i)?(f[cur^1][j][0][1]*C2(A[i]+1)%kcz+f[cur^1][j][1][1]*(A[i]*p%kcz+kcz-C2(A[i]+1))%kcz+f[cur^1][j][0][0]*C2(p+1)%kcz+f[cur^1][j][1][0]*C2(p)%kcz)%kcz:0;
            f[cur][j][0][1]=(j<i)?(f[cur^1][j][0][1]*(A[i]+1)%kcz+f[cur^1][j][1][1]*(p-1-A[i])%kcz)%kcz:0;
            f[cur][j][1][0]=j?(f[cur^1][j-1][0][1]*C2(A[i])%kcz+f[cur^1][j-1][1][1]*(A[i]*p%kcz+kcz-C2(A[i]))%kcz+f[cur^1][j-1][0][0]*C2(p)%kcz+f[cur^1][j-1][1][0]*C2(p+1)%kcz)%kcz:0;
            f[cur][j][1][1]=j?(f[cur^1][j-1][0][1]*A[i]%kcz+f[cur^1][j-1][1][1]*(p-A[i])%kcz)%kcz:0;
            // printf("(%lld,%lld,%lld,%lld) ",f[cur][j][0][0],f[cur][j][0][1],f[cur][j][1][0],f[cur][j][1][1]);
        }
    for(i=a,ans=0;i<=len;i++)
        (ans+=f[cur][i][0][0]+f[cur][i][0][1])%=kcz;
    printf("%lld\n",ans);
    return 0;
}