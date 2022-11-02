#include<cstdio>
char c;
int i,j,s,n,k,L=1,R,m,a[500000];
int main()
{
//	freopen("singer.in","r",stdin);
//	freopen("singer.out","w",stdout);
	scanf("%d\n",&k);
	for(;~(c=getchar());++R)
		if(++a[n],c==32||c==45)++n;
	for(--a[n];L<R;)
	{
		m=L+R>>1;
		for(i=j=s=0;i<=n&&j<k;++i)
			if(a[i]>m)j=k;else
			if((s+=a[i])>m)++j,s=a[i];
		if(j<k)R=m;else L=m+1;
	}
	printf("%d",L);
}