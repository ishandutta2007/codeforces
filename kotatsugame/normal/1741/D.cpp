#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		vector<int>P(N);
		for(int i=0;i<N;i++)cin>>P[i];
		int ans=0,len=1;
		bool ok=true;
		while(ok&&P.size()>=2)
		{
			vector<int>Q;
			Q.reserve(P.size()/2);
			for(int i=0;i<P.size();i+=2)
			{
				if(P[i]+len==P[i+1])Q.push_back(P[i]);
				else if(P[i+1]+len==P[i])ans++,Q.push_back(P[i+1]);
				else
				{
					ok=false;
					break;
				}
			}
			P=Q;
			len*=2;
		}
		cout<<(ok?ans:-1)<<"\n";
	}
}