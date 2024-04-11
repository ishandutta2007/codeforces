#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,N;
int A[2021];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		bool ok=true;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			A[i]--;
			if(i%2!=A[i]%2)ok=false;
		}
		if(!ok)
		{
			puts("-1");
			continue;
		}
		vector<int>ans;
		for(int k=N-1;k>0;k-=2)
		{
			int e,o;
			for(int i=0;i<N;i++)
			{
				if(A[i]==k-1)e=i;
				if(A[i]==k)o=i;
			}
			if(e<o)
			{
				ans.push_back(o+1);
				reverse(A,A+o+1);
				e=o-e;
				o=0;
			}
			else
			{
				ans.push_back(o+1);
				reverse(A,A+o+1);
				o=0;
			}
			ans.push_back(e);
			reverse(A,A+e);
			o=e-1;
			ans.push_back(e+2);
			reverse(A,A+e+2);
			e=1;
			o=2;
			ans.push_back(o+1);
			reverse(A,A+o+1);
			e=1;
			o=0;
			ans.push_back(k+1);
			reverse(A,A+k+1);
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++)printf("%d%c",ans[i],i+1==ans.size()?10:32);
	}
}