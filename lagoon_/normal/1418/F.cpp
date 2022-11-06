#include<bits/stdc++.h>
#define re register
int yy1[200100],xx2[200100],yy2[200100];
void sol(re int i,re int g,re int k,re int v)
{
	yy1[i]=k*v;
	xx2[i]=g*v;
	yy2[i]=i/g*k;
}
int main()
{
	re int n,m;
	re long long L,R;
	scanf("%d%d%lld%lld",&n,&m,&L,&R);
	for(re int g=1;g<=n;g++)
	{
		for(re int v=1;v<n/g;v++)
		if(!yy1[g*v]){
			re long long lm=(L-1)/g/v+1,rm=std::min((R/g/v),1ll*m),l=(lm-1)/(n/g)+1,r=rm/(v+1);
			if(lm>rm||l>r)continue;
			if(rm/l>(lm-1)/l){sol(g*v,g,l,std::max(1ll*v+1,(lm-1)/l+1));continue;}
			for(re int i=l;i<=r;)
			{
				re int cr=rm/i,cl=(lm-1)/i;
				if(cr>cl){sol(g*v,g,i,std::max(v+1,cl+1));break;}
				i=std::min((lm-1)/cl,rm/cr)+1;
			}
		}
	}
	for(re int i=1;i<=n;i++)if(yy1[i])printf("%d %d %d %d\n",i,yy1[i],xx2[i],yy2[i]);else puts("-1");
}