#include<iostream>
#include<algorithm>
using namespace std;
int T,N;
int A[50];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		sort(A,A+N);
		int cnt=0;
		for(int i=0;i<N;)
		{
			int j=i;
			while(j<N&&A[i]==A[j])j++;
			cnt+=j-i-1;
			i=j;
		}
		cout<<N-(cnt+1)/2*2<<"\n";
	}
}