#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int a,b,c;cin>>a>>b>>c;
		int x=a-1;
		int y=abs(b-c)+c-1;
		cout<<(x<y?1:x>y?2:3)<<"\n";
	}
}