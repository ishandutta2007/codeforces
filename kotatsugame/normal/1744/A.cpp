#include<iostream>
#include<vector>
using namespace std;
int N;
string S;
vector<int>ids[51];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=1;i<=50;i++)ids[i].clear();
		for(int i=0;i<N;i++)
		{
			int a;cin>>a;
			ids[a].push_back(i);
		}
		cin>>S;
		bool ok=true;
		for(int i=1;i<=50;i++)if(!ids[i].empty())
		{
			char c=S[ids[i][0]];
			for(int j:ids[i])if(c!=S[j])ok=false;
		}
		cout<<(ok?"YES\n":"NO\n");
	}
}