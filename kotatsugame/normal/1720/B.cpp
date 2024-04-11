#include<iostream>
#include<algorithm>
using namespace std;
int N,A[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		sort(A,A+N);
		cout<<A[N-1]+A[N-2]-A[0]-A[1]<<"\n";
	}
}