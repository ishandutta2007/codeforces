#include<iostream>
using namespace std;
int N;
string s;
main()
{
	cin>>N>>s;
	int nl=0,pre=-1;
	int ans=0;
	for(int i=0;i<N;i++)
	{
		if(s[i]=='(')nl++;
		else nl--;
		if(nl<0&&pre<0)pre=i;
		else if(nl==0&&pre>=0)
		{
			ans+=i-pre+1;
			pre=-1;
		}
	}
	cout<<(nl==0?ans:-1)<<endl;
}