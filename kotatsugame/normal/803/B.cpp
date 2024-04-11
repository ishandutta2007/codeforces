#include<iostream>
#include<queue>
using namespace std;
int N;
int A[2<<17],d[2<<17];
main()
{
	cin>>N;
	queue<int>P;
	for(int i=0;i<N;i++)
	{
		d[i]=1e9;
		cin>>A[i];
		if(!A[i])P.push(i),d[i]=0;
	}
	while(!P.empty())
	{
		int i=P.front();
		P.pop();
		for(int j=i-1;j<=i+1;j+=2)
		{
			if(j>=0&&j<N&&d[j]>d[i]+1)
			{
				d[j]=d[i]+1;
				P.push(j);
			}
		}
	}
	for(int i=0;i<N;i++)cout<<d[i]<<(i+1==N?"\n":" ");
}