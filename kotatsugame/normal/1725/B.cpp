#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,D;
	cin>>N>>D;
	deque<int>Q;
	for(int i=0;i<N;i++)
	{
		int p;cin>>p;
		Q.push_back(p);
	}
	sort(Q.begin(),Q.end());
	int ans=0;
	while(!Q.empty())
	{
		int p=Q.back();Q.pop_back();
		int c=D/p;
		while(c>0&&!Q.empty())Q.pop_front(),c--;
		if(c>0)break;
		ans++;
	}
	cout<<ans<<endl;
}