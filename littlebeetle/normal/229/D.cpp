#include<cstdio>
const int N=100002;
int n,i,a[N],s[N],f[N],q[N],d[N],h[N],S,E;
int main(){	
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",a+i);
    for(i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    for(i=1;i<=n;i++){
        while(S<E&&s[i]>=f[q[S+1]]+s[q[S+1]])
            S++;
        f[i]=s[i]-s[q[S]];
        h[i]=h[q[S]]+1;
        while(S<=E&&s[q[E]]+f[q[E]]>=s[i]+f[i])
            E--;
        q[++E]=i;
    }
    printf("%d",n-h[n]);
    return 0;
}