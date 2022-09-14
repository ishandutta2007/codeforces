#include<iostream>
#include<stack>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;
		string S;
		cin>>N>>S;
		stack<int>V;
		int ans=0,cnt=0;
		for(int i=0;i<2*N;i++)
		{
			if(S[i]=='(')
			{
				while(!V.empty()&&V.top()>cnt)V.pop();
				if(V.empty()||V.top()<cnt)
				{
					V.push(cnt);
					ans++;
				}
				cnt++;
			}
			else
			{
				cnt--;
			}
		}
		cout<<ans<<"\n";
	}
}