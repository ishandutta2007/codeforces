#include<iostream>
using namespace std;
int A[100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;
		cin>>N;
		cout<<N<<"\n";
		for(int i=0;i<N;i++)A[i]=i+1;
		for(int i=0;i<N;i++)cout<<A[i]<<(i+1==N?"\n":" ");
		for(int j=1;j<N;j++)
		{
			swap(A[j-1],A[j]);
			for(int i=0;i<N;i++)cout<<A[i]<<(i+1==N?"\n":" ");
		}
	}
}