#include<iostream>
using namespace std;
int T;
string S;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>S;
		int now=0;
		bool out=false;
		for(char c:S)
		{
			if(c>='a'&&c<='z')
			{
				now|=1<<(c=='r'?0:c=='g'?1:2);
			}
			else
			{
				if(!(now>>(c=='R'?0:c=='G'?1:2)&1))
				{
					out=true;
					break;
				}
			}
		}
		cout<<(out?"NO\n":"YES\n");
	}
}