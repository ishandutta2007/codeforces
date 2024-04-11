#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		for(int i=1;i<=N;i++)
		{
			cout<<(i==1?1:i==N?2:i+1)<<(i==N?"\n":" ");
		}
	}
}