#include<iostream>
using namespace std;
int N,P[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		if(N==3)
		{
			cout<<"-1\n";
			continue;
		}
		else if(N==2)
		{
			cout<<"2 1\n";
			continue;
		}
		for(int i=0;i<N;i++)P[i]=(i+2)%N+1;
		for(int i=0;i<N;i++)cout<<P[i]<<(i+1==N?"\n":" ");
	}
}