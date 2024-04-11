#include<iostream>
#include<deque>
using namespace std;
int T,N;
int A[1<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		bool ok=true;
		int prv=0;
		deque<int>P;
		for(int i=0;i<N;i++)
		{
			if(P.empty())P.push_back(A[i]);
			else if(P.back()<=A[i])
			{
				if(P.back()%2==A[i]%2)P.push_back(A[i]);
				else
				{
					prv=P.back();
					while(!P.empty())P.pop_back();
					P.push_back(A[i]);
				}
			}
			else
			{
				if(P.back()%2==A[i]%2||prv>A[i])
				{
					ok=false;
					break;
				}
				prv=A[i];
				while(P.front()<=A[i])P.pop_front();
			}
		}
		cout<<(ok?"Yes\n":"No\n");
	}
}