#include<iostream>
#include<queue>
using namespace std;
int T,N;
string s,t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>s>>t;
		queue<int>idx[3];
		for(int i=0;i<N;i++)idx[s[i]-'a'].push(i);
		idx[0].push(N);
		idx[1].push(N);
		idx[2].push(N);
		bool ok=true;
		for(int i=0;i<N;i++)
		{
			int a=idx[0].front();
			int b=idx[1].front();
			int c=idx[2].front();
			if(t[i]=='a')
			{
				if(a<b&&a<c)idx[0].pop();
				else
				{
					ok=false;
					break;
				}
			}
			else if(t[i]=='b')
			{
				if(b<c)idx[1].pop();
				else
				{
					ok=false;
					break;
				}
			}
			else
			{
				if(c<a)idx[2].pop();
				else
				{
					ok=false;
					break;
				}
			}
		}
		cout<<(ok?"YES\n":"NO\n");
	}
}