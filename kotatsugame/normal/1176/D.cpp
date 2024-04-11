#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int LIM=2750131;
int isp[LIM+1];
vector<int>primes;
int N;
main()
{
	for(int i=2;i<=LIM;i++)
	{
		if(isp[i]==0)primes.push_back(i);
		for(int j=i+i;j<=LIM;j+=i)isp[j]=i;
	}
	scanf("%d",&N);
	vector<int>B(2*N);
	for(int i=0;i<2*N;i++)scanf("%d",&B[i]);
	multiset<int>S(B.begin(),B.end());
	multiset<int>ps;
	vector<int>A;
	while(!S.empty())
	{
		int u=*S.rbegin();S.erase(--S.end());
		if(isp[u]==0)ps.insert(u);
		else
		{
			A.push_back(u);
			S.erase(S.find(isp[u]));
		}
	}
	while(!ps.empty())
	{
		int p=*ps.begin();ps.erase(ps.begin());
		A.push_back(p);
		ps.erase(ps.find(primes[p-1]));
	}
	for(int i=0;i<N;i++)printf("%d%c",A[i],i+1==N?10:32);
}