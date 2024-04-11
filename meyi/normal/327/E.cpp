#include<cstdio>
#define ri register int
const int maxn=1<<24;
inline int lowbit(int x){return x&-x;}
int a[25],d[maxn],k,m[2],n,s[maxn];
main(){
    d[0]=1;
	scanf("%d",&n);
	for(ri i=0;i<n;++i)scanf("%d",a+i),s[1<<i]=a[i];
	scanf("%d",&k);
	for(ri i=0;i<k;++i)scanf("%d",m+i);
	for(ri i=1;i<(1<<n);++i){
		s[i]=s[lowbit(i)]+s[i&~lowbit(i)];
		if(s[i]!=m[0]&&s[i]!=m[1])
			for(ri j=i;j;j-=lowbit(j))
				d[i]=(d[i]+d[i&~lowbit(j)])%1000000007;
	}
	printf("%d",d[(1<<n)-1]);
}