#include<bits/stdc++.h>
using namespace std;
#define re register
long long a1[1001000];
int a2[1001000],q[1001000];
int main()
{
	re int n,w,l;
	scanf("%d%d",&n,&w);
	for(re int i1=1;i1<=n;i1++)
	{
		scanf("%d",&l);
		re int ta=0;
		for(re int i=1;i<=l;i++)
			scanf("%d",&a2[i]);
		a2[l+1]=0;
		for(re int i=1;i<=l+1;i++)
		{
			while(ta>=1&&a2[q[ta-1]]>=a2[q[ta]]&&a2[i]>=a2[q[ta]]&&q[ta-1]+w-l>=i-1)ta--;
			q[++ta]=i;
		}
		re int x1=q[1];
		if(a2[q[1]]<0)x1=w-l+1;
		for(re int i=1;i<=ta;i++)
		{
			a1[x1]+=a2[q[i]];
			if(i<ta)
			{
				if(a2[q[i]]<a2[q[i+1]])x1=q[i+1];
				else x1=q[i]+w-l+1;
				a1[x1]-=a2[q[i]];
			}
		}
	}
	for(re int i=1;i<=w;i++)a1[i]+=a1[i-1],printf("%lld ",a1[i]);
}