#include<iostream>
#include<vector>
using namespace std;
int N;
main()
{
	scanf("%d",&N);
	int p=-1;
	vector<int>ans;
	for(int i=0;i<N;i++)
	{
		int A;
		scanf("%d",&A);
		if(A==1)
		{
			if(p>0)ans.push_back(p);
		}
		p=A;
	}
	ans.push_back(p);
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d%c",ans[i],i+1==ans.size()?10:32);
}