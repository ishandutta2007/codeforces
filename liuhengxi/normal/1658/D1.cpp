#include<cstdio>
#define F for(int i=0;i<r-l;++i)
#define t(x) if(c(x)){printf("%d\n",x);goto ok;}
int T,l,r,a[1<<17],b[1<<17];int c(int x){for(int i=l;i<r;++i)if(!b[i^x])return 0;return 1;}main(){for(scanf("%d",&T);T--;){scanf("%d%d",&l,&r);++r;F scanf("%d",a+i),b[a[i]]=1;int k=l|r;k&=-k;F if(!b[a[i]^k])t((a[i]^(l&k?l:r-1)));ok:;F b[a[i]]=0;}}