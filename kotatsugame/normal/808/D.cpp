#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int N,A[1<<17];
main()
{
	cin>>N;
	long long S=0;
	multiset<int>X;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		S+=A[i];
		X.insert(A[i]);
	}
	for(int i=0;i<N;i++)
	{
		S-=2*A[i];
		X.erase(X.find(A[i]));
		X.insert(-A[i]);
		if(S%2==0&&abs(S/2)<=(long long)1e9)
		{
			int T=S/2;
			if(X.find(T)!=X.end())
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
}