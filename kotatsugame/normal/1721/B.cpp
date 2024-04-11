#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N,M,sx,sy,d;
		cin>>N>>M>>sx>>sy>>d;
		if(sy-1>d&&N-sx>d||sx-1>d&&M-sy>d)cout<<N-1+M-1<<"\n";
		else cout<<"-1\n";
	}
}