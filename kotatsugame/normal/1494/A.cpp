#include<iostream>
using namespace std;
int T;
string A,B;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>A;
		bool fn=false;
		for(int a=0;a<2;a++)for(int b=0;b<2;b++)for(int c=0;c<2;c++)
		{
			B=A;
			int mn=0,cnt=0;
			for(int i=0;i<B.size();i++)
			{
				int t=B[i]=='A'?a:B[i]=='B'?b:c;
				if(t==0)B[i]='(';
				else B[i]=')';
				if(B[i]=='(')cnt++;
				else cnt--;
				if(mn>cnt)mn=cnt;
			}
			if(mn==0&&cnt==0)fn=true;
		}
		cout<<(fn?"YES\n":"NO\n");
	}
}