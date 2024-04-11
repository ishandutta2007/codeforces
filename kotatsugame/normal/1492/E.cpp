#include<cstdio>
#include<vector>
using namespace std;
void disp(const vector<int>&a)
{
	for(int i=0;i<a.size();i++)printf("%d%c",a[i],i+1==a.size()?10:32);
}
int N,M;
int cnt[252525];
int buk[5];
vector<vector<int> >A;
bool zero()
{
	return !(buk[3]||buk[4]);
}
int one(int k)
{
	if(buk[3]||buk[4])return-2;
	if(buk[2])
	{
		int id=0;
		while(cnt[id]!=2)id++;
		for(int i=0;i<N;i++)if(A[i][k]!=A[id][k])
		{
			buk[cnt[i]]--;
			cnt[i]++;
			buk[cnt[i]]++;
		}
		bool fn=zero();
		for(int i=0;i<N;i++)if(A[i][k]!=A[id][k])
		{
			buk[cnt[i]]--;
			cnt[i]--;
			buk[cnt[i]]++;
		}
		if(fn)return A[id][k];
		else return-2;
	}
	else return-1;
}
pair<int,int>two(int j,int k)
{
	if(buk[3]||buk[4])return make_pair(-2,-2);
	else if(buk[2])
	{
		int id=0;
		while(cnt[id]!=2)id++;
		for(int i=0;i<N;i++)
		{
			if(A[i][j]!=A[id][j])
			{
				buk[cnt[i]]--;
				cnt[i]++;
				buk[cnt[i]]++;
			}
			if(A[i][k]!=A[id][k])
			{
				buk[cnt[i]]--;
				cnt[i]++;
				buk[cnt[i]]++;
			}
		}
		bool fn=zero();
		for(int i=0;i<N;i++)
		{
			if(A[i][j]!=A[id][j])
			{
				buk[cnt[i]]--;
				cnt[i]--;
				buk[cnt[i]]++;
			}
			if(A[i][k]!=A[id][k])
			{
				buk[cnt[i]]--;
				cnt[i]--;
				buk[cnt[i]]++;
			}
		}
		if(fn)return make_pair(A[id][j],A[id][k]);
		else return make_pair(-2,-2);
	}
	else if(buk[1])
	{
		int id=0;
		while(cnt[id]!=1)id++;
		for(int i=0;i<N;i++)if(A[i][j]!=A[id][j])
		{
			buk[cnt[i]]--;
			cnt[i]++;
			buk[cnt[i]]++;
		}
		int t=one(k);
		for(int i=0;i<N;i++)if(A[i][j]!=A[id][j])
		{
			buk[cnt[i]]--;
			cnt[i]--;
			buk[cnt[i]]++;
		}
		if(t!=-2)
		{
			return make_pair(A[id][j],t);
		}
		for(int i=0;i<N;i++)if(A[i][k]!=A[id][k])
		{
			buk[cnt[i]]--;
			cnt[i]++;
			buk[cnt[i]]++;
		}
		t=one(j);
		for(int i=0;i<N;i++)if(A[i][k]!=A[id][k])
		{
			buk[cnt[i]]--;
			cnt[i]--;
			buk[cnt[i]]++;
		}
		if(t!=-2)
		{
			return make_pair(t,A[id][k]);
		}
		else return make_pair(-2,-2);
	}
	else return make_pair(-1,-1);
}
main()
{
	scanf("%d%d",&N,&M);
	A=vector<vector<int> >(N,vector<int>(M));
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)scanf("%d",&A[i][j]);
	vector<vector<int> >did(M);
	buk[0]=M;
	for(int j=0;j<M;j++)
	{
		for(int i=0;i<N;i++)if(A[0][j]!=A[i][j])
		{
			did[j].push_back(i);
			buk[cnt[i]]--;
			if(++cnt[i]==5)
			{
				puts("No");
				return 0;
			}
			buk[cnt[i]]++;
		}
	}
	if(zero())
	{
		puts("Yes");
		disp(A[0]);
		return 0;
	}
	for(int j=0;j<M;j++)
	{
		for(int id:did[j])
		{
			buk[cnt[id]]--;
			cnt[id]--;
			buk[cnt[id]]++;
		}
		{
			int t=one(j);
			if(t!=-2)
			{
				vector<int>ans=A[0];
				if(t!=-1)ans[j]=t;
				puts("Yes");
				disp(ans);
				return 0;
			}
		}
		if(!buk[4])
		{
			for(int k=j+1;k<M;k++)
			{
				for(int id:did[k])
				{
					buk[cnt[id]]--;
					cnt[id]--;
					buk[cnt[id]]++;
				}
				pair<int,int>p=two(j,k);
				if(p.first!=-2)
				{
					vector<int>ans=A[0];
					if(p.first!=-1)ans[j]=p.first;
					if(p.second!=-1)ans[k]=p.second;
					puts("Yes");
					disp(ans);
					return 0;
				}
				for(int id:did[k])
				{
					buk[cnt[id]]--;
					cnt[id]++;
					buk[cnt[id]]++;
				}
			}
		}
		for(int id:did[j])
		{
			buk[cnt[id]]--;
			cnt[id]++;
			buk[cnt[id]]++;
		}
	}
	puts("No");
}