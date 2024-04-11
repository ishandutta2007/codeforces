#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T;
main()
{
	cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		vector<string>A(N);
		for(int i=0;i<N;i++)cin>>A[i];
		int ans=0;
		for(char c='a';c<='e';c++)
		{
			vector<int>B(N,0);
			for(int i=0;i<N;i++)
			{
				for(char d:A[i])B[i]+=c==d?1:-1;
			}
			sort(B.begin(),B.end());
			int cnt=0,all=0;
			for(int i=N;i--;)
			{
				all+=B[i];
				if(all>0)cnt++;
				else break;
			}
			if(ans<cnt)ans=cnt;
		}
		cout<<ans<<endl;
	}
}