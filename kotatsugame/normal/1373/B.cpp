#include<iostream>
using namespace std;
int T;
string S;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>S;
		bool now=true;
		while(true)
		{
			bool ok=false;
			for(int i=0;i+1<S.size();i++)
			{
				if(S[i]!=S[i+1])
				{
					S=S.substr(0,i)+S.substr(i+2);
					ok=true;
					break;
				}
			}
			if(!ok)break;
			now=!now;
		}
		cout<<(now?"NET":"DA")<<endl;
	}
}