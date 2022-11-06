#include<bits/stdc++.h>
using namespace std;
#define re register
long long ll,l1;
int n,a1[1010],lm[1010],la;
long long al[1010],aan[1010],vla[1010];
long long find(re int a,re long long val,re long long l,re long long r)
{
	for(re long long mid=(l+r)/2;l<r;mid=(l+r)/2)
	{
		printf("?\n%d %lld\n",a,mid);
		fflush(stdout);
		re long long f;scanf("%lld",&f);
		if(f>=val)r=mid;
		else l=mid+1;
	}return l;
}
inline bool cmp(re int a,re int b){return vla[a]>vla[b];}
void sol(re long long l,re long long r,re int n,re int*a)
{
	if(n==1){lm[a[1]]=la;al[a[1]]=r;la=a[1];return;}
	int aa[n+10],aa1[n+10],nn=n,x,nn1=0,nn2=0,q,q1,q2;
	re long long an,an1,vl=l1*(n/2);
	while(1)
	{
		x=rand()%nn+1;//assert(aan[a[x]]+vl<=ll);
		an=find(a[x],aan[a[x]]+vl,l,r);q=q1=q2=0;//assert(an<=1000000000000000000ll);
		for(re int i=1;i<=nn;i++)
		{
			printf("?\n%d %lld\n",a[i],an);
			fflush(stdout);
			scanf("%lld",&vla[a[i]]);vla[a[i]]-=aan[a[i]];
			if(vla[a[i]]>vl)q++;else if(vla[a[i]]==vl)q2++;else q1++;
		}
		sort(a+1,a+nn+1,cmp);
		if(q+nn1<=n/2&&q1+nn2<=n-n/2)
		{
			while(nn1<n/2)aa[++nn1]=*(++a);
			while(nn2<n-n/2)aa1[++nn2]=*(++a);
			for(re int i=1;i<=nn2;i++)
			{
				printf("?\n%d %lld\n",aa1[i],an);
				fflush(stdout);re long long ff=aan[aa1[i]];
				scanf("%lld",&aan[aa1[i]]);assert(ff+vl>=aan[aa1[i]]);
			}assert(nn1==n/2&&nn2==n-n/2);
			sol(l,an,nn1,aa);
			sol(an+1,r,nn2,aa1);
			return;
		}
		if(q+nn1<=n/2)
		{
			re int nk=q+q2+nn1;
			while(nn1<nk)aa[++nn1]=*(++a);
			nn=n-nn1-nn2;
		}
		else
		{
			re int nk=nn-q1-q2;
			while(nn>nk)aa1[++nn2]=a[nn--];
		}
	}
}
int main()
{
	srand(time(0));
	scanf("%d%lld",&n,&ll);
	l1=ll/n;
	for(re int i=1;i<=n;i++)a1[i]=i;
	sol(1,1000000000000000000ll,n,a1);
	puts("!");
	for(re int i=1;i<=n;i++)
	{
		printf("%lld %lld\n",al[lm[i]],al[i]);
	}
}