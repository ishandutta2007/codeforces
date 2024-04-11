#include<cstdio>
static char buf[100000],*p1=buf,*p2=buf;
#define gc p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
inline int read()
{
    register int x=0;register char a=gc;
    while(a<'0'||a>'9')a=gc;
    while(a>='0'&&a<='9')x=(x<<1)+(x<<3)+(a^48),a=gc;
    return x;
}
char pbuf[10000000] , *pp = pbuf;
inline void write(int x)
{
    static int sta[35];
    register int top = 0;
    if(!x)sta[++top]=0;
    while(x) sta[++top] = x % 10 , x /= 10;
    while(top) *pp ++ = sta[top -- ] ^ '0';
}
unsigned int n=read(),a[205001],b[205001];
#define run register unsigned int
main()
{
    run i,*j,*lim,bac1[301]={0},bac2[301]={0},bac3[301]={0},bac4[301]={0},tmp;
    for(i=1;i<=n;++i)a[i]=read();
    for(j=a+1,lim=a+n+1;j!=lim;++j)++bac1[(tmp=(*j))&255],++bac2[(tmp>>8)&255],++bac3[(tmp>>16)&255],++bac4[tmp>>24];
    for(i=1;i<=255;++i)bac1[i]+=bac1[i-1],bac2[i]+=bac2[i-1],bac3[i]+=bac3[i-1],bac4[i]+=bac4[i-1];
    for(j=a+n;j!=a;--j)b[bac1[(*j)&255]--]=*j;
    for(j=b+n;j!=b;--j)a[bac2[((*j)>>8)&255]--]=*j;
    for(j=a+n;j!=a;--j)b[bac3[((*j)>>16)&255]--]=*j;
    for(j=b+n;j!=b;--j)a[bac4[(*j)>>24]--]=*j;
    for(i=1;i<=n;++i)write(a[i]),*pp ++ = ' ';
    fwrite(pbuf , 1 , pp - pbuf , stdout);
}