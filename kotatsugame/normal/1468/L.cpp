#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,K;
long long X[1010],pX[1010];
vector<int>p[1010];
int is_p(int x)
{
	for(int i=2;i*i<=x;i++)if(x%i==0)
	{
		while(x%i==0)x/=i;
		if(x==1)return i;
		else return -1;
	}
	return x;
}
bool ex[1010];
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%lld",&X[i]);
		pX[i]=X[i];
	}
	vector<int>ps;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)if(i!=j&&X[j]%X[i]==0)
		{
			long long x=X[i],y=X[j]/X[i];
			if(x<y)swap(x,y);
			while(y!=1)
			{
				if(x%y!=0)break;
				long long t=x/y;
				x=y;
				y=t;
				if(x<y)swap(x,y);
			}
			if(y==1)
			{
				int now=is_p(x);
				if(now>=2)ps.push_back(now);
			}
		}
	}
	sort(ps.begin(),ps.end());ps.erase(unique(ps.begin(),ps.end()),ps.end());
	vector<vector<int> >ok(ps.size());
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<ps.size();j++)if(X[i]%ps[j]==0)
		{
			while(X[i]%ps[j]==0)X[i]/=ps[j];
			p[i].push_back(j);
		}
		if(X[i]==1&&p[i].size()==1)
		{
			ok[p[i][0]].push_back(i);
		}
	}
	int all=0,del=0;
	for(int i=0;i<ps.size();i++)if(ok[i].size()>=2)
	{
		ex[i]=true;
		all+=ok[i].size();
		del+=ok[i].size()-2;
	}
	vector<int>ans;
	if(all<=K)
	{
		for(int i=0;i<N;i++)if(X[i]==1&&p[i].size()==1&&ex[p[i][0]])
		{
			ans.push_back(i);
		}
		for(int i=0;i<N;i++)if(X[i]==1&&p[i].size()>1&&ans.size()<K)
		{
			bool now=true;
			for(int j:p[i])if(!ex[j])now=false;
			if(now)ans.push_back(i);
		}
	}
	else
	{
		vector<vector<int> >app(ps.size());
		for(int i=0;i<N;i++)if(X[i]==1&&p[i].size()==1&&ex[p[i][0]])
		{
			app[p[i][0]].push_back(i);
		}
		if(all-del<=K)
		{
			for(int i=0;i<ps.size();i++)if(!app[i].empty())
			{
				for(int j=0;j<2;j++)ans.push_back(app[i][j]);
			}
			for(int i=0;i<ps.size();i++)
			{
				for(int j=2;j<app[i].size()&&ans.size()<K;j++)ans.push_back(app[i][j]);
			}
		}
		else if(K%2==0)
		{
			for(int i=0;i<ps.size();i++)if(!app[i].empty()&&ans.size()<K)
			{
				for(int j=0;j<2;j++)ans.push_back(app[i][j]);
			}
		}
		else if(K>=3)
		{
			int fn=-1;
			for(int i=0;i<ps.size();i++)if(app[i].size()>=3)fn=i;
			if(fn>=0)
			{
				for(int i=0;i<3;i++)ans.push_back(app[fn][i]);
				for(int i=0;i<ps.size();i++)if(fn!=i&&!app[i].empty()&&ans.size()<K)
				{
					for(int j=0;j<2;j++)ans.push_back(app[i][j]);
				}
			}
			else
			{
				int fn=-1;
				for(int i=0;i<N;i++)if(X[i]==1&&p[i].size()>1)
				{
					bool now=true;
					for(int j:p[i])if(!ex[j])now=false;
					if(now&&1+2*p[i].size()<=K)
					{
						fn=i;
						break;
					}
				}
				if(fn>=0)
				{
					ans.push_back(fn);
					vector<bool>used(ps.size(),false);
					for(int j:p[fn])
					{
						used[j]=true;
						for(int k=0;k<2;k++)ans.push_back(app[j][k]);
					}
					for(int i=0;i<ps.size();i++)if(!used[i]&&!app[i].empty()&&ans.size()<K)
					{
						for(int j=0;j<2;j++)ans.push_back(app[i][j]);
					}
				}
			}
		}
	}
	if(ans.size()<K)puts("0");
	else
	{
		for(int i=0;i<K;i++)printf("%lld%c",pX[ans[i]],i+1==K?10:32);
	}
}