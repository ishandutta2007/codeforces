#include<iostream>
using namespace std;
int N;
int A[2<<17],B[2<<17];
bool ok[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		for(int i=0;i<N;i++)cin>>B[i];
		{
			int id=0;
			for(int i=0;i<N;i++)
			{
				while(B[id]<A[i])id++;
				cout<<B[id]-A[i]<<(i+1==N?"\n":" ");
				ok[i]=id<i;
			}
		}
		{
			int id=0;
			for(int i=0;i<N;i++)
			{
				if(id<i)id=i;
				while(id+1<N&&ok[id+1])id++;
				cout<<B[id]-A[i]<<(i+1==N?"\n":" ");
			}
		}
	}
}