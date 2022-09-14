#include<cstdio>
#include<vector>
using namespace std;
int T;
long long N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld\n",&N);
		N--;
		long long now=1;
		vector<int>ans;
		while(true)
		{
			if(N>now*4)
			{
				ans.push_back(now);
				N-=now+=now;
			}
			else
			{
				if(N>now*3)
				{
					int T=N-now*3;
					ans.push_back(T);
					N-=now+T;
					ans.push_back(now-T);
					N-=now+now;
				}
				else if(N>now*2)
				{
					int T=(N-now*2)/2;
					ans.push_back(T);
					N-=now+T;
					if((N-now-T)%2==1)
					{
						ans.push_back(1);
						T++;
					}
					else ans.push_back(0);
					N-=now+T;
				}
				else
				{
					ans.push_back(N-now);
					N-=now=N;
				}
				break;
			}
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++)printf("%d%c",ans[i],i+1==ans.size()?'\n':' ');
	}
}