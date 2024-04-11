#include<iostream>
#include<vector>
using namespace std;
int T,N;
vector<int>id[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=1;i<=N;i++)id[i].clear();
		for(int i=0;i<N;i++)
		{
			int c;cin>>c;id[c].push_back(i);
		}
		for(int i=1;i<=N;i++)
		{
			int e=0,o=0;
			for(int j:id[i])
			{
				if(j%2==0)e=max(e,o+1);
				else o=max(o,e+1);
			}
			cout<<max(e,o)<<" \n"[i==N];
		}
	}
}