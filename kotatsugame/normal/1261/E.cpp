#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int N;
int A[1010];
int id[1010],inv[1010];
int ans[1010][1010];
main()
{
	scanf("%d",&N);
	vector<pair<int,int> >B(N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		B[i]=make_pair(-A[i],i);
	}
	sort(B.begin(),B.end());
	for(int i=0;i<N;i++)
	{
		id[i]=B[i].second;
		inv[id[i]]=i;
	}
	for(int i=0;i<N;i++)
	{
		if(A[id[i]]==N-i)
		{
			for(int j=0;j<N-i;j++)ans[j][i]=1;
			bool fn=false;
			for(int j=i+1;j<N;j++)if(A[id[j]]==N-i)
			{
				A[id[j]]--;
				ans[N-i][j]=1;
				fn=true;
			}
		}
		else
		{
			for(int j=0;j<A[id[i]];j++)ans[N-i-j-1][i]=1;
		}
	}
	vector<string>ret;
	for(int i=0;i<=N;i++)
	{
		string now="";
		bool fn=false;
		for(int j=0;j<N;j++)
		{
			now+=(char)(ans[i][inv[j]]+'0');
			if(ans[i][inv[j]])fn=true;
		}
		if(fn)ret.push_back(now);
	}
	printf("%d\n",(int)ret.size());
	for(string s:ret)printf("%s\n",s.c_str());
}