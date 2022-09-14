#include<iostream>
using namespace std;
int N;
int cnt[101];
int way[101][10001];
main()
{
	cin>>N;
	int sum=0;
	int sp=0;
	for(int i=0;i<N;i++)
	{
		int a;cin>>a;
		if(cnt[a]==0)sp++;
		cnt[a]++;
		sum+=a;
	}
	way[0][0]=1;
	int prv=0;
	for(int i=1;i<=100;i++)if(cnt[i]>0)
	{
		int a=i;
		for(int k=prv;k>=0;k--)
		{
			for(int x=1;x<=cnt[i];x++)
			{
				int b=a*x;
				for(int l=10000-b;l>=0;l--)
				{
					way[k+x][l+b]+=way[k][l];
					if(way[k+x][l+b]>2)way[k+x][l+b]=2;
				}
			}
		}
		prv+=cnt[i];
	}
	int ans=1;
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=cnt[i];j++)
		{
			if(way[j][i*j]==1&&ans<j)ans=j;
			if(way[j][i*j]==1&&j==cnt[i])
			{
				if(sp==2)ans=N;
			}
			if(way[N-j][sum-i*j]==1&&ans<j)ans=j;
		}
	}
	cout<<ans<<endl;
}