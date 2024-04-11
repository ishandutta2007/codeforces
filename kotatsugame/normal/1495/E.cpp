#include<cstdio>
#include<vector>
using namespace std;
const long long mod=1e9+7;
int N,M;
int a[5<<20];
bool t[5<<20];
int ans[5<<20];
main()
{
	scanf("%d%d",&N,&M);
	int prv=0;
	for(int i=0;i<M;i++)
	{
		int p,k,b,w;
		scanf("%d%d%d%d",&p,&k,&b,&w);
		int seed=b,base=w;
		while(prv<p)
		{
			t[prv]=seed%2;
			seed=((long long)seed*base+233)%mod;
			a[prv]=seed%k+1;
			seed=((long long)seed*base+233)%mod;
			prv++;
		}
	}
	ans[0]++;
	a[0]--;
	int id=0;
	while(id<N&&t[0]==t[id])id++;
	if(id<N)
	{
		vector<long long>sum;
		vector<int>L;
		vector<vector<int> >ids;
		sum.push_back(a[id]);
		L.push_back(id);
		for(int i=1;i<N;i++)
		{
			int idx=(id+i)%N;
			if(t[(idx+N-1)%N]==t[idx])
			{
				sum.back()+=a[idx];
			}
			else
			{
				sum.push_back(a[idx]);
				L.push_back(idx);
			}
		}
		long long X=0,Y=0;
		int n=sum.size();
		for(int i=0;i<n;i++)
		{
			if(i%2==0)X+=sum[i];
			else Y+=sum[i];
		}
		if(X==Y)
		{
			for(int i=0;i<N;i++)ans[i]+=a[i];
		}
		else if(X<Y)
		{
			for(int i=0;i<n;i+=2)
			{
				int l=L[i],r;
				if(i+1<n)r=L[i+1];
				else r=L[0];
				for(int id=l;id!=r;id=(id+1)%N)ans[id]+=a[id];
			}
			long long pr=0;
			for(int i=1;i<n*2;i+=2)
			{
				pr+=sum[(i-1)%n];sum[(i-1)%n]=0;
				long long now=min(pr,sum[i%n]);
				pr-=now;
				sum[i%n]-=now;
				int l=L[i%n],r;
				if(i%n+1<n)r=L[i%n+1];
				else r=L[0];
				for(int id=l;id!=r;id=(id+1)%N)
				{
					if(a[id]<now)
					{
						ans[id]+=a[id];
						now-=a[id];
						a[id]=0;
					}
					else
					{
						ans[id]+=now;
						a[id]-=now;
						now=0;
					}
				}
			}
		}
		else
		{
			a[id]--;
			ans[id]++;
			{
				int i=0;
				while(i<N&&t[id]==t[(id+i)%N])i++;
				id=(id+i)%N;
			}
			vector<long long>sum;
			vector<int>L;
			vector<vector<int> >ids;
			sum.push_back(a[id]);
			L.push_back(id);
			for(int i=1;i<N;i++)
			{
				int idx=(id+i)%N;
				if(t[(idx+N-1)%N]==t[idx])
				{
					sum.back()+=a[idx];
				}
				else
				{
					sum.push_back(a[idx]);
					L.push_back(idx);
				}
			}
			long long X=0,Y=0;
			int n=sum.size();
			for(int i=0;i<n;i++)
			{
				if(i%2==0)X+=sum[i];
				else Y+=sum[i];
			}
			if(X==Y)
			{
				for(int i=0;i<N;i++)ans[i]+=a[i];
			}
			else if(X<Y)
			{
				for(int i=0;i<n;i+=2)
				{
					int l=L[i],r;
					if(i+1<n)r=L[i+1];
					else r=L[0];
					for(int id=l;id!=r;id=(id+1)%N)ans[id]+=a[id];
				}
				long long pr=0;
				for(int i=1;i<n*2;i+=2)
				{
					pr+=sum[(i-1)%n];sum[(i-1)%n]=0;
					long long now=min(pr,sum[i%n]);
					pr-=now;
					sum[i%n]-=now;
					int l=L[i%n],r;
					if(i%n+1<n)r=L[i%n+1];
					else r=L[0];
					for(int id=l;id!=r;id=(id+1)%N)
					{
						if(a[id]<now)
						{
							ans[id]+=a[id];
							now-=a[id];
							a[id]=0;
						}
						else
						{
							ans[id]+=now;
							a[id]-=now;
							now=0;
						}
					}
				}
			}
		}
	}
	long long ret=1;
	for(int i=0;i<N;i++)
	{
		long long t=ans[i];
		t^=(long long)(i+1)*(i+1);
		t+=1;
		t%=mod;
		ret=ret*t%mod;
	}
	printf("%lld\n",ret);
}