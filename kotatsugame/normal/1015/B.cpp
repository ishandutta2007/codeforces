#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
char S[55],T[55];
main()
{
	scanf("%d%s%s",&N,S,T);
	vector<int>ans;
	for(int i=0;i<N;i++)
	{
		int j=i;
		while(j<N&&S[j]!=T[i])j++;
		if(j==N)
		{
			puts("-1");
			return 0;
		}
		for(int k=j-1;k>=i;k--)
		{
			ans.push_back(k);
			swap(S[k],S[k+1]);
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d%c",ans[i]+1,i+1==ans.size()?10:32);
}