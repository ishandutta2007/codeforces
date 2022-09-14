#include<cstdio>
#include<map>
#include<vector>
using namespace std;
int N;
map<int,int>mp;
int B[2<<17];
main()
{
	scanf("%d",&N);
	int k=0,x;
	for(int i=0;i<N;i++)
	{
		int A;
		scanf("%d",&A);
		B[i]=A;
		int now=1;
		if(mp.find(A-1)!=mp.end())now+=mp[A-1];
		if(mp[A]<now)mp[A]=now;
		if(k<now)
		{
			k=now;
			x=A;
		}
	}
	vector<int>ids;
	for(int i=N;i--;)
	{
		if(B[i]==x)
		{
			ids.push_back(i+1);
			x--;
		}
	}
	printf("%d\n",k);
	for(int i=0;i<k;i++)printf("%d%c",ids[k-i-1],i+1==k?10:32);
}