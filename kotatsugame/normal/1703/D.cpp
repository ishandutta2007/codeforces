#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string>A[9];
string S[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		for(int i=1;i<=8;i++)A[i].clear();
		for(int i=0;i<N;i++)
		{
			cin>>S[i];
			A[S[i].size()].push_back(S[i]);
		}
		for(int i=1;i<=8;i++)sort(A[i].begin(),A[i].end());
		for(int i=0;i<N;i++)
		{
			bool fn=false;
			for(int l=1;l<S[i].size();l++)
			{
				int r=S[i].size()-l;
				auto lt=lower_bound(A[l].begin(),A[l].end(),S[i].substr(0,l));
				auto rt=lower_bound(A[r].begin(),A[r].end(),S[i].substr(l));
				if(lt!=A[l].end()&&rt!=A[r].end()&&*lt==S[i].substr(0,l)&&*rt==S[i].substr(l))
				{
					fn=true;
					break;
				}
			}
			cout<<(fn?'1':'0');
		}
		cout<<"\n";
	}
}