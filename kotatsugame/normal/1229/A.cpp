#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int N;
long long A[7000];
long long B[7000];
long long ans;
main()
{
	cin>>N;
	vector<long long>X;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		X.push_back(A[i]);
	}
	for(int i=0;i<N;i++)cin>>B[i];
	sort(X.begin(),X.end());
	vector<long long>Y;
	for(int i=0;i<N;i++)
	{
		if(i+1<N&&X[i]==X[i+1])
		{
			while(i+1<N&&X[i]==X[i+1])i++;
			Y.push_back(X[i]);
		}
	}
	for(int i=0;i<N;i++)
	{
		bool flag=false;
		for(long long OK:Y)if(!(~OK&A[i]))flag=true;
		if(flag)ans+=B[i];
	}
	cout<<ans<<endl;
}