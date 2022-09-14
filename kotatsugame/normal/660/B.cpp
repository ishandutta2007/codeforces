#include<iostream>
using namespace std;
int N,M;
int A[100][4];
bool fst=true;
void f(int x)
{
	if(x)
	{
		if(fst)fst=false;
		else cout<<" ";
		cout<<x;
	}
}
main()
{
	cin>>N>>M;
	for(int i=1;i<=M;i++)
	{
		if(i<=2*N)
		{
			A[(i-1)/2][i%2==1?0:3]=i;
		}
		else
		{
			A[(i-2*N-1)/2][i%2==1?1:2]=i;
		}
	}
	for(int i=0;i<N;i++)
	{
		f(A[i][1]);
		f(A[i][0]);
		f(A[i][2]);
		f(A[i][3]);
	}
	cout<<endl;
}