#include<bits/stdc++.h>
#define re register
char ss[5010];
int tt[210],pp1[110],pp2[110],ans[110];
char rt[110];
int lg[(1<<20)+1],ls[(1<<20)+1],rs[(1<<20)+1],ns[(1<<20)+1],nm[(1<<20)+1],ff[(1<<20)+1],ll[110],rr[110],nn[110];
inline bool cmp1(re int a,re int b){return ll[a]<ll[b];}
inline bool cmp2(re int a,re int b){return rr[a]<rr[b];}
int main()
{
	re int n,a,b,cn=0,N,nans=0;
	scanf("%d%d%d%s",&n,&a,&b,ss+1);
	for(re int i=1;i<=n;i++)
	{
		tt[ss[i]]=1;
	}
	for(re int i=0;i<26;i++)
	if(tt[i+'a']){
		rt[cn]=i+'a';
		tt[i+'a']=cn++;
	}
	N=1<<cn;
	for(re int i=0;i<cn;i++)ll[i]=10000,lg[1<<i]=i,pp1[i]=pp2[i]=i;
	for(re int i=1;i<=n;i++)
	{
		re int x=tt[ss[i]];
		nn[x]++;ll[x]=std::min(i,ll[x]);rr[x]=std::max(i,rr[x]);
	}
	std::sort(pp1,pp1+cn,cmp1);
	std::sort(pp2,pp2+cn,cmp2);
	ls[0]=10000;
	for(re int i=1;i<N;i++)
	{
		ls[i]=std::min(ls[i-(i&-i)],ll[lg[i&-i]]);
		rs[i]=std::max(rs[i-(i&-i)],rr[lg[i&-i]]);
		nm[i]=std::max(nm[i-(i&-i)],nn[lg[i&-i]]);
		ns[i]=ns[i-(i&-i)]+nn[lg[i&-i]];
	}
	for(re int kk=0;kk<cn;kk++)
	{
		memset(ff,0,sizeof(ff));
		ff[0]=1;
		for(re int j1=0;j1<cn;j1++)
		{
			re int j=pp2[j1];
			for(re int i1=cn-1;i1>=0;i1--)
			{
				re int i=pp1[i1],S=0,nc=0,len=rr[j]-ll[i]+1;
				if(i==kk||j==kk)continue;
				if(ll[j]<ll[i]||rr[i]>rr[j])continue;
				for(re int ii=0;ii<cn;ii++)if(ll[ii]>=ll[i]&&rr[ii]<=rr[j]&&ii!=kk)S+=1<<ii;
				for(re int ii=S;;ii=(ii-1)&S)
				{
					if(ff[ii])nc=std::max(nc,(int)ns[ii]+nm[S-ii]);
					if(!ii)break;
				}
				if(1ll*nc*b>=1ll*a*len)
				{
					re int T=0;
					for(re int ii=0;ii<cn;ii++)if(rr[ii]<ll[i]&&ii!=kk)T+=1<<ii;
					for(re int ii=T;;ii=(ii-1)&T)
					{
						ff[ii+S]|=ff[ii];
						if(!ii)break;
					}
				}
			}
		}
		if(ff[N-1-(1<<kk)])ans[kk]=1,nans++;
	}
	printf("%d ",nans);
	for(re int kk=0;kk<cn;kk++)if(ans[kk])printf("%c ",rt[kk]);puts("");
}