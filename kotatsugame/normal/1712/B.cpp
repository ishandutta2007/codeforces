#include<iostream>
using namespace std;
int N,P[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=N;i>=1;i-=2)
		{
			if(i==1)P[i]=i;
			else
			{
				P[i]=i-1;
				P[i-1]=i;
			}
		}
		for(int i=1;i<=N;i++)cout<<P[i]<<(i==N?"\n":" ");
	}
}