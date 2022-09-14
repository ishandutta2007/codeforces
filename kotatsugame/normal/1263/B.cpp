#include<iostream>
#include<set>
using namespace std;
int N,T;
string s[10];
bool F[10];
main()
{
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>N;
		int ans=0;
		set<string>S;
		for(int j=0;j<N;j++)
		{
			cin>>s[j];
			if(S.find(s[j])==S.end())
			{
				S.insert(s[j]);
				F[j]=false;
			}
			else F[j]=true;
		}
		for(int j=0;j<N;j++)
		{
			if(!F[j])
			{
				continue;
			}
			ans++;
			for(int k=0;k<4;k++)
			{
				bool flag=false;
				for(char c='0';c<='9';c++)
				{
					if(s[j][k]==c)continue;
					string t=s[j];
					t[k]=c;
					if(S.find(t)==S.end())
					{
						S.insert(t);
						s[j]=t;
						flag=true;
						break;
					}
				}
				if(flag)break;
			}
		}
		cout<<ans<<endl;
		for(int j=0;j<N;j++)cout<<s[j]<<endl;
	}
}