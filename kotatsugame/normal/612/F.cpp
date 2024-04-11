#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,S;
int A[2000];
main()
{
	cin>>N>>S;
	S--;
	vector<pair<int,int> >X(N);
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		X[i]=make_pair(A[i],i);
	}
	sort(X.begin(),X.end());
	vector<vector<int> >tmp;
	tmp.push_back(vector<int>{S});
	for(int i=0;i<X.size();)
	{
		tmp.push_back(vector<int>());
		int j=i;
		while(j<X.size()&&X[i].first==X[j].first)
		{
			tmp.back().push_back(X[j].second);
			j++;
		}
		i=j;
	}
	vector<vector<int> >dp;
	dp.push_back(vector<int>{0});
	for(int i=1;i<tmp.size();i++)
	{
		vector<int>nxt(tmp[i].size(),2e9);
		int n=tmp[i].size();
		for(int x=0;x<dp.back().size();x++)
		{
			int pos=tmp[i-1][x];
			for(int y=0;y<n;y++)
			{
				int to=tmp[i][y];
				{
					int prv=tmp[i][(y+1)%n];
					int d=min((pos-prv+N)%N,(prv-pos+N)%N)+(to-prv+N)%N;
					d+=dp.back()[x];
					if(nxt[y]>d)nxt[y]=d;
				}
				{
					int prv=tmp[i][(y-1+n)%n];
					int d=min((pos-prv+N)%N,(prv-pos+N)%N)+(prv-to+N)%N;
					d+=dp.back()[x];
					if(nxt[y]>d)nxt[y]=d;
				}
			}
		}
		dp.push_back(nxt);
	}
	int mid=0;
	for(int i=1;i<dp.back().size();i++)if(dp.back()[mid]>dp.back()[i])mid=i;
	cout<<dp.back()[mid]<<"\n";
	vector<int>ans;
	for(int i=dp.size()-1;i>=1;i--)
	{
		int use;
		int nmid=-1;
		int n=tmp[i].size();
		for(int x=0;x<dp[i-1].size();x++)
		{
			int pos=tmp[i-1][x];
			int y=mid;
			int to=tmp[i][y];
			{
				int prv=tmp[i][(y+1)%n];
				int d=min((pos-prv+N)%N,(prv-pos+N)%N)+(to-prv+N)%N;
				d+=dp[i-1][x];
				if(dp[i][y]==d)
				{
					nmid=x;
					use=1;
					break;
				}
			}
			{
				int prv=tmp[i][(y-1+n)%n];
				int d=min((pos-prv+N)%N,(prv-pos+N)%N)+(prv-to+N)%N;
				d+=dp[i-1][x];
				if(dp[i][y]==d)
				{
					nmid=x;
					use=-1;
					break;
				}
			}
		}
		int pos=tmp[i-1][nmid];
		int prv;
		int y=mid;
		if(use==1)
		{
			for(int j=1;j<n;j++)
			{
				int d=(tmp[i][(y-j+1+n)%n]-tmp[i][(y-j+n)%n]+N)%N;
				ans.push_back(d);
			}
			prv=tmp[i][(y+1)%n];
		}
		else
		{
			for(int j=0;j<n-1;j++)
			{
				int d=(tmp[i][(y+j+1)%n]-tmp[i][(y+j)%n]+N)%N;
				ans.push_back(-d);
			}
			prv=tmp[i][(y-1+n)%n];
		}
		if((pos-prv+N)%N<=(prv-pos+N)%N)
		{
			ans.push_back(-((pos-prv+N)%N));
		}
		else
		{
			ans.push_back((prv-pos+N)%N);
		}
		mid=nmid;
	}
	reverse(ans.begin(),ans.end());
	for(int d:ans)
	{
		if(d>=0)cout<<'+'<<d;
		else cout<<d;
		cout<<'\n';
	}
}