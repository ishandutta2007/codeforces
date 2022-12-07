#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2000010;
char str[MAXN],tmp[MAXN],s[MAXN];
int n,Q,k,d,D[MAXN],M[MAXN],P[MAXN],A[MAXN],B[MAXN],C[MAXN],tot;
void qpow(int len,int n)
{
    if(n==1) return;
    qpow(len,n>>1);
    for(int i=1;i<=len;i++) A[i]=B[i]=P[i];
    for(int i=1;i<=len;i++) P[i]=A[B[i]];
    if(!(n&1)) return;
    for(int i=1;i<=len;i++) A[i]=P[i];
    for(int i=1;i<=len;i++) P[i]=A[C[i]];
}
int main()
{
    scanf("%s%d",str+1,&Q);
    n=strlen(str+1);
    while(Q--)
    {
        scanf("%d%d",&k,&d);
        tot=n-1;
        for(int r=0;r<d;r++)
            for(int i=n+r;i<n+k;i+=d)
                D[i]=++tot;
        for(int i=1;i<n;i++) D[i]=i;
        for(int i=n+k;i<=n+n;i++) D[i]=i;
        for(int i=1;i<=n+n;i++) M[i]=i-1;
        M[1]=n+n;
        for(int i=1;i<=n+n;i++) C[i]=P[i]=D[M[i]];
        qpow(n+n,n-k+1);
        for(int i=1;i<=n+n;i++) tmp[i]=s[i]=0;
        for(int i=1;i<=n;i++) tmp[n+i]=str[i];
        for(int i=1;i<=n+n;i++) s[P[i]]=tmp[i];
        for(int i=k;i<n+k;i++) str[i-k+1]=s[i];
        puts(str+1);
    }
    return 0;
}