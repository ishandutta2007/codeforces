#include<iostream>
using namespace std;
int T,N,A[50];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		int fi,mn=2e9;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			if(mn>A[i])
			{
				fi=i;
				mn=A[i];
			}
		}
		cout<<(N%2==1||fi%2==1?"Mike\n":"Joe\n");
	}
}