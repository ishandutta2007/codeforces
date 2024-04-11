#include<iostream>
#include<stack>
using namespace std;
int N;
string s;
long long ans,now;
main()
{
	cin>>N>>s;
	stack<int>S;
	long long cnt=0;
	for(int i=N;i--;)
	{
		if(s[i]=='1')
		{
			cnt++;
			if(S.empty())now+=N-i;
			else
			{
				now+=S.top()-i;
				S.pop();
			}
		}
		else
		{
			for(;cnt;cnt--)
			{
				S.push(i+cnt);
			}
		}
		ans+=now;
	}
	cout<<ans<<endl;
}