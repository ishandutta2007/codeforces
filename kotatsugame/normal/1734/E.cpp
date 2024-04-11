#include<iostream>
using namespace std;
int N;
int A[350][350];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>A[i][i];
		A[i][0]=(A[i][i]-i*i%N+N)%N;
	}
	for(int i=0;i<N;i++)
	{
		for(int j=1;j<N;j++)A[i][j]=(A[i][j-1]+i)%N;
		for(int j=0;j<N;j++)cout<<A[i][j]<<(j+1==N?"\n":" ");
	}
}