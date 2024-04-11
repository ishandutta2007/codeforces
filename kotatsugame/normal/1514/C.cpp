#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int N;
main()
{
	scanf("%d",&N);
	vector<int>ans;
	ans.push_back(1);
	int p=1;
	for(int i=2;i<N-i;i++)
	{
		if(gcd(N,i)==1)
		{
			p=(long long)p*i%N*(N-i)%N;
			ans.push_back(i);
			ans.push_back(N-i);
		}
	}
	sort(ans.begin(),ans.end());
	if(N>2)
	{
		if(p==N-1)ans.push_back(N-1);
		else if(p!=1)
		{
			puts("ERROR");
			return 1;
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d%c",ans[i],i+1==ans.size()?10:32);
}