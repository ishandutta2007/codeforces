#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
main()
{
	cin>>N>>M;
	vector<pair<int,int> >C;
	for(int i=0;i<N;i++)
	{
		int p,c;cin>>p>>c;
		if(p!=1)C.push_back(make_pair(c,p-1));
	}
	sort(C.begin(),C.end());
	reverse(C.begin(),C.end());
	long long ans=9e18;
	for(int i=1;i<=N;i++)
	{
		vector<int>cnt(M);
		int rest=N-i;
		long long need=0;
		for(int j=0;j<C.size();j++)
		{
			if(rest>0&&cnt[C[j].second]+1<i)
			{
				cnt[C[j].second]++;
				rest--;
			}
			else need+=C[j].first;
		}
		if(ans>need)ans=need;
	}
	cout<<ans<<endl;
}