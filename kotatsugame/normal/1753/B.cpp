#include<iostream>
using namespace std;
int N,X;
int cnt[5<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>X;
	for(int i=0;i<N;i++)
	{
		int a;cin>>a;
		cnt[a]++;
	}
	for(int i=1;i<X;i++)
	{
		cnt[i+1]+=cnt[i]/(i+1);
		cnt[i]%=i+1;
		if(cnt[i]>0)
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
}