#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int N;
long long cumsum[1<<20];
main()
{
	scanf("%d",&N);
	stack<pair<int,long long> >id;
	long long H;
	scanf("%lld",&H);
	id.push(make_pair(0,H));
	for(int i=1;i<N;i++)
	{
		scanf("%lld",&H);
		while(id.size()>=2)
		{
			int n=i-id.top().first;
			long long Hp=id.top().second+n-1;
			long long t=H-Hp-1;
			if(t>=n)
			{
				id.pop();
				H-=n;
				continue;
			}
			else
			{
				if(t>=1)
				{
					int beg=id.top().first;
					long long se=id.top().second;
					id.pop();
					id.push(make_pair(beg+t,se+t));
					H-=t;
				}
				break;
			}
		}
		if(id.size()==1)
		{
			int n=i;
			long long Hp=id.top().second+n-1;
			if(Hp+2<=H)
			{
				long long t=(H-Hp-2)/(n+1);
				id.top().second+=t;
				H-=t*n;
				Hp+=t;
				while(true)
				{
					t=H-Hp-1;
					if(t>=n)
					{
						id.top().second+=1;
						H-=n;
						Hp+=1;
					}
					else
					{
						if(t>=1)
						{
							id.top().second+=1;
							H-=t;
							long long fst=id.top().second;
							id.push(make_pair(t,fst+t-1));
						}
						break;
					}
				}
			}
		}
		if(id.top().second+i-id.top().first>H)id.push(make_pair(i,H));
	}
	vector<pair<int,long long> >A(id.size());
	for(int i=0;i<A.size();i++)
	{
		A[A.size()-i-1]=id.top();
		id.pop();
	}
	long long now;
	int j=0;
	for(int i=0;i<N;i++)
	{
		now++;
		if(j<A.size()&&A[j].first==i)
		{
			now=A[j++].second;
		}
		printf("%lld%c",now,i+1==N?'\n':' ');
	}
}