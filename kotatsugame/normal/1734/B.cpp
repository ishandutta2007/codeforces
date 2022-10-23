#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;
		cin>>N;
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=i;j++)
			{
				cout<<(j==1||j==i?1:0);
				cout<<(j==i?"\n":" ");
			}
		}
	}
}