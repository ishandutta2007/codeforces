#include<iostream>
#include<queue>
#include<stack>
using namespace std;
string S,U;
queue<int>id[26];
main()
{
	cin>>S;
	for(int i=0;i<S.size();i++)id[S[i]-'a'].push(i);
	stack<char>T;
	int si=0;
	for(int _=0;_<S.size();_++)
	{
		char mx=T.empty()?'z'+1:T.top();
		for(char c='a';c<mx;c++)
		{
			if(!id[c-'a'].empty())
			{
				int need=id[c-'a'].front();
				while(si<=need)
				{
					T.push(S[si]);
					id[S[si]-'a'].pop();
					si++;
				}
				break;
			}
		}
		U+=T.top();
		T.pop();
	}
	cout<<U<<endl;
}