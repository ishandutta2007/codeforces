#include<iostream>
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
		cout<<(N%3==0?N/3:N%3==2?N/3+1:N==1?2:N/3+1)<<"\n";
	}
}