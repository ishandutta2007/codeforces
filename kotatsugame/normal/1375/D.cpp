#include<cstdio>
#include<vector>
using namespace std;
int T,N;
int A[1001];
int ex[1001];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			ex[i]=0;
		}
		ex[N]=0;
		int tm=0;
		vector<int>ans;
		while(true)
		{
			tm++;
			for(int i=0;i<N;i++)ex[A[i]]=tm;
			int id=0;
			while(ex[id]==tm)id++;
			if(id==N)break;
			ans.push_back(id+1);
			A[id]=id;
		}
		for(int i=0;i<N;i++)if(A[i]!=i)
		{
			int now=i;
			do{
				ans.push_back(now+1);
				int tmp=A[now];
				A[now]=now;
				now=tmp;
			}while(now!=i);
			ans.push_back(now+1);
		}
		printf("%d\n",(int)ans.size());
		for(int i=0;i<ans.size();i++)
		{
			printf("%d",ans[i]);
			if(i+1<ans.size())printf(" ");
		}
		puts("");
	}
}