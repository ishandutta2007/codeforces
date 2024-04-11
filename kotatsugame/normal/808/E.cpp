#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
vector<int>C[3];
long long sum[3][1<<17];
main()
{
	cin>>N>>M;
	for(int i=0;i<N;i++)
	{
		int w,c;cin>>w>>c;
		C[w-1].push_back(c);
	}
	for(int i=0;i<3;i++)
	{
		sort(C[i].begin(),C[i].end());
		reverse(C[i].begin(),C[i].end());
		sum[i][0]=0;
		for(int j=0;j<C[i].size();j++)sum[i][j+1]=sum[i][j]+C[i][j];
	}
	long long ans=0;
	for(int a=0;a<=C[2].size();a++)
	{
		int rest=M-3*a;
		if(rest<0)break;
		const auto f=[&rest](int x){
			return sum[1][x]+sum[0][min(rest-2*x,(int)C[0].size())];
		};
		int L=0,R=min(rest/2,(int)C[1].size());
		while(R-L>2)
		{
			int m1=(L+L+R)/3,m2=(L+R+R)/3;
			if(f(m1)>f(m2))R=m2;
			else L=m1;
		}
		for(int b=L;b<=R;b++)ans=max(ans,sum[2][a]+f(b));
	}
	cout<<ans<<endl;
}