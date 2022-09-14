#include<cstdio>
#include<map>
using namespace std;
int N;
int A[121212];
main()
{
	scanf("%d",&N);
	map<int,int>mp;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		mp[A[i]]++;
	}
	int cnt=0;
	for(int i=0;i<N;i++)
	{
		bool fn=false;
		mp[A[i]]--;
		for(int j=1;j<=30;j++)
		{
			int t=(1<<j)-A[i];
			if(mp.find(t)!=mp.end()&&mp[t]>0)fn=true;
		}
		if(!fn)cnt++;
		mp[A[i]]++;
	}
	printf("%d\n",cnt);
}