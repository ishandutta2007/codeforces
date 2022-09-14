#include<iostream>
using namespace std;
int T;
string S;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>S;
		int d=0;
		for(int i=0;i<S.size();)
		{
			d++;
			int now=0;
			while(i<S.size())
			{
				now|=1<<(S[i++]-'a');
				if(__builtin_popcount(now)==4)
				{
					i--;
					break;
				}
			}
		}
		cout<<d<<"\n";
	}
}