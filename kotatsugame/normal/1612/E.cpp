#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int cnt[21];
vector<pair<int,int> >T[21];
main()
{
	scanf("%d",&N);
	vector<pair<int,int> >A(N);
	for(int i=0;i<N;i++)
	{
		int m,k;
		scanf("%d%d",&m,&k);
		A[i]=make_pair(m,k);
	}
	sort(A.begin(),A.end());
	for(int i=0;i<N;)
	{
		int m=A[i].first;
		int j=i;
		for(int k=1;k<=20;k++)cnt[k]=0;
		while(j<N&&A[j].first==m)
		{
			cnt[A[j].second]++;
			j++;
		}
		int num=j-i;
		int other=0;
		i=j;
		for(int k=1;k<=20;k++)
		{
			T[k].push_back(make_pair(other+num*k,m));
			num-=cnt[k];
			other+=cnt[k]*k;
		}
	}
	vector<int>ans;
	long long P=0,Q=1;
	for(int k=1;k<20;k++)if(T[k].size()>=k)
	{
		sort(T[k].begin(),T[k].end());
		reverse(T[k].begin(),T[k].end());
		long long nP=0,nQ=k;
		for(int i=0;i<k;i++)nP+=T[k][i].first;
		if(P*nQ<nP*Q)
		{
			P=nP;
			Q=nQ;
			ans.clear();
			for(int i=0;i<k;i++)ans.push_back(T[k][i].second);
		}
	}
	if(T[20].size()>=20)
	{
		sort(T[20].begin(),T[20].end());
		reverse(T[20].begin(),T[20].end());
		long long nP=0,nQ=0;
		int mi=-1;
		for(int i=0;i<T[20].size();i++)
		{
			nP+=T[20][i].first;
			nQ++;
			if(i>=19&&P*nQ<nP*Q)
			{
				P=nP;
				Q=nQ;
				mi=i;
			}
		}
		if(mi!=-1)
		{
			ans.clear();
			for(int i=0;i<=mi;i++)ans.push_back(T[20][i].second);
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d%c",ans[i],i+1==ans.size()?10:32);
}