#include<iostream>
using namespace std;
int n,a[444];
int cnt[1111];
int out[22][22];
main()
{
	cin>>n;
	for(int i=0;i<n*n;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	if(n%2==0)
	{
		int ret=0;
		for(int i=1;i<=1000;i++)ret+=cnt[i]%4>0;
		if(ret>0)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		cout<<"YES"<<endl;
		int id=0;
		for(int i=1;i<=1000;i++)
		{
			while(cnt[i]>0)
			{
				int x=id/(n/2),y=id%(n/2);
				id++;
				out[x][y]=out[n-x-1][n-y-1]=out[x][n-y-1]=out[n-x-1][y]=i;
				cnt[i]-=4;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)cout<<out[i][j]<<(j==n-1?"\n":" ");
		}
	}
	else
	{
		int one=0,two=0;
		for(int i=1;i<=1000;i++)
		{
			if(cnt[i]%2==1)
			{
				one++;
				out[n/2][n/2]=i;
				cnt[i]--;
			}
			if(cnt[i]%4==2)
			{
				if(two<n-1)
				{
					if(two%2)
					{
						out[n/2][two/2]=out[n/2][n-two/2-1]=i;
					}
					else
					{
						out[two/2][n/2]=out[n-two/2-1][n/2]=i;
					}
				}
				cnt[i]-=2;
				two++;
			}
		}
		if(one!=1||two>n-1||two%2)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		cout<<"YES"<<endl;
		int id=0;
		for(int i=1;i<=1000;i++)
		{
			while(cnt[i]>0)
			{
				if(id<(n-1)/2*(n-1)/2)
				{
					int x=id/((n-1)/2),y=id%((n-1)/2);
					id++;
					out[x][y]=out[n-x-1][n-y-1]=out[x][n-y-1]=out[n-x-1][y]=i;
					cnt[i]-=4;
				}
				else
				{
					out[two/2][n/2]=out[n-two/2-1][n/2]=out[n/2][two/2]=out[n/2][n-two/2-1]=i;
					two+=2;
					cnt[i]-=4;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)cout<<out[i][j]<<(j==n-1?"\n":" ");
		}
	}
}