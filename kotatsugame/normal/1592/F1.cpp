#include<iostream>
#include<algorithm>
using namespace std;
int N,M;
string S[500];
int pp[501][500];
int pc[500];
main()
{
	cin>>N>>M;
	for(int i=0;i<N;i++)
	{
		cin>>S[i];
		S[i]+='W';
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			pp[i][j]=S[i][j]!=S[i][j+1];
		}
	}
	int ans=0;
	for(int j=0;j<M;j++)
	{
		for(int i=0;i<=N;)
		{
			int k=i;
			while(k<=N&&pp[i][j]==pp[k][j])k++;
			i=k;
			pc[j]++;
		}
		ans+=pc[j];
	}
	int all=ans;
	for(int x=0;x<N;x++)for(int y=0;y<M;y++)
	{
		int now=all+3;
		if(y>0)
		{
			int j=y-1;
			now-=pc[j];
			for(int i=0;i<=N;)
			{
				int k=i;
				int need=pp[i][j]^(x<=i&&i<N);
				while(k<=N&&need==(pp[k][j]^(x<=k&&k<N)))k++;
				i=k;
				now++;
			}
		}
		{
			int j=M-1;
			now-=pc[j];
			for(int i=0;i<=N;)
			{
				int k=i;
				int need=pp[i][j]^(x<=i&&i<N);
				while(k<=N&&need==(pp[k][j]^(x<=k&&k<N)))k++;
				i=k;
				now++;
			}
		}
		if(ans>now)ans=now;
	}
	cout<<ans-M<<endl;
}