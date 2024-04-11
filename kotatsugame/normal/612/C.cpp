#include<iostream>
#include<stack>
using namespace std;
string S;
main()
{
	cin>>S;
	int ans=0;
	stack<char>Q;
	for(char c:S)
	{
		if(c==')')
		{
			if(Q.empty())
			{
				cout<<"Impossible"<<endl;
				return 0;
			}
			ans+=Q.top()!='(';
			Q.pop();
		}
		else if(c=='}')
		{
			if(Q.empty())
			{
				cout<<"Impossible"<<endl;
				return 0;
			}
			ans+=Q.top()!='{';
			Q.pop();
		}
		else if(c=='>')
		{
			if(Q.empty())
			{
				cout<<"Impossible"<<endl;
				return 0;
			}
			ans+=Q.top()!='<';
			Q.pop();
		}
		else if(c==']')
		{
			if(Q.empty())
			{
				cout<<"Impossible"<<endl;
				return 0;
			}
			ans+=Q.top()!='[';
			Q.pop();
		}
		else Q.push(c);
	}
	if(Q.empty())cout<<ans<<endl;
	else cout<<"Impossible"<<endl;
}