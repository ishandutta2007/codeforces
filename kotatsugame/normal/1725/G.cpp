#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;cin>>N;
	long long L=0,R=1e18;
	while(R-L>1)
	{
		long long mid=(L+R)/2;
		long long cnt=(mid-1)/2+(mid-4)/4;
		if(cnt>=N)R=mid;
		else L=mid;
	}
	cout<<R<<endl;
}