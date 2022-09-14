#include<iostream>
#include<algorithm>
using namespace std;
int T,N,P[2<<17];
int ans[2<<17];
string S;
vector<pair<int,int> >A;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>P[i];
		cin>>S;
		int l=1;
		for(int c=0;c<2;c++)
		{
			A.clear();
			for(int i=0;i<N;i++)if(S[i]-'0'==c)
			{
				A.push_back(make_pair(P[i],i));
			}
			sort(A.begin(),A.end());
			for(int i=0;i<A.size();i++)
			{
				ans[A[i].second]=l++;
			}
		}
		for(int i=0;i<N;i++)cout<<ans[i]<<(i+1==N?"\n":" ");
	}
}