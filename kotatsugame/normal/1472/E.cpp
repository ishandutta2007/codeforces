#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N;
int H[2<<17],W[2<<17];
int ans[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		vector<pair<int,int> >hi(N);
		for(int i=0;i<N;i++)
		{
			ans[i]=-2;
			scanf("%d%d",&H[i],&W[i]);
			if(H[i]>W[i])swap(H[i],W[i]);
			hi[i]=make_pair(H[i],i);
		}
		sort(hi.begin(),hi.end());
		int mj=-1,j=0;
		for(int i=0;i<N;i++)
		{
			int id=hi[i].second;
			while(hi[j].first<H[id])
			{
				int jd=hi[j].second;
				if(mj==-1||W[mj]>W[jd])mj=jd;
				j++;
			}
			if(mj!=-1&&W[mj]<W[id])ans[id]=mj;
		}
		for(int i=0;i<N;i++)printf("%d%c",ans[i]+1,i+1==N?10:32);
	}
}