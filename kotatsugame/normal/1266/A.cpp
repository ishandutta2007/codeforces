#include<iostream>
using namespace std;
int N;
main()
{
	cin>>N;
	for(;N--;)
	{
		string s;cin>>s;
		int sum=0;
		int exs[10]={};
		for(int i=0;i<s.size();i++)
		{
			sum+=s[i]-'0';
			exs[s[i]-'0']++;
		}
		sum*=4;
		if(exs[0]==0)cout<<"cyan"<<endl;
		else
		{
			exs[0]--;
			bool flag=false;
			for(int i=0;i<10;i++)
			{
				if(exs[i]==0)continue;
				if((sum-3*i)%6==0)flag=true;
			}
			cout<<(flag?"red":"cyan")<<endl;
		}
	}
}