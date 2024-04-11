#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ull=unsigned long long;
ull xorshift()
{
	static ull x=88172645463325252uLL;
	x^=x<<7;
	return x^=x>>9;
}
ull Hash[1<<20];
int N;
int isp[1<<20];
vector<int>ps;
ull fac[1<<20];
main()
{
	cin>>N;
	for(int i=2;i<=N;i++)isp[i]=-1;
	for(int i=2;i<=N;i++)if(isp[i]<0)
	{
		ps.push_back(i);
		for(int j=i;j<=N;j+=i)isp[j]=i;
	}
	for(int p:ps)Hash[p]=xorshift();
	ull cur=0,all=0;
	for(int i=1;i<=N;i++)
	{
		int x=i;
		while(x>1)
		{
			cur^=Hash[isp[x]];
			x/=isp[x];
		}
		fac[i]=cur;
		all^=cur;
	}
	vector<int>ans;
	if(all==0)
	{
		for(int i=1;i<=N;i++)ans.push_back(i);
	}
	else
	{
		int fn=-1;
		for(int i=1;i<=N;i++)if(all==fac[i])
		{
			fn=i;
			break;
		}
		if(fn!=-1)
		{
			for(int i=1;i<=N;i++)if(i!=fn)ans.push_back(i);
		}
		else
		{
			vector<pair<ull,int> >del(N);
			for(int i=1;i<=N;i++)
			{
				del[i-1]=make_pair(all^fac[i],i);
			}
			sort(del.begin(),del.end());
			int x=-1,y;
			for(int i=1;i<=N;i++)
			{
				auto it=lower_bound(del.begin(),del.end(),make_pair(fac[i],0));
				if(it!=del.end()&&it->first==fac[i])
				{
					x=it->second;
					y=i;
					break;
				}
			}
			if(x!=-1)
			{
				for(int i=1;i<=N;i++)if(i!=x&&i!=y)ans.push_back(i);
			}
			else
			{
				int n=N/2;
				for(int i=1;i<=n*2;i++)if(i!=2&&i!=n)ans.push_back(i);
			}
		}
	}
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<(i+1==ans.size()?"\n":" ");
}