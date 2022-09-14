#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int T,N;
int A[2<<17];
vector<int>can;
bool f(int X)
{
	int l=0,r=N-1;
	while(l<r)
	{
		if(A[l]==X)l++;
		else if(A[r]==X)r--;
		else if(A[l]==A[r])l++,r--;
		else return false;
	}
	return true;
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		can.clear();
		for(int i=0;i<N;i++)
		{
			int j=N-i-1;
			if(A[i]!=A[j])
			{
				can.push_back(A[i]);
				can.push_back(A[j]);
				break;
			}
		}
		if(can.empty())
		{
			puts("YES");
			continue;
		}
		if(f(can[0])||f(can[1]))puts("YES");
		else puts("NO");
	}
}