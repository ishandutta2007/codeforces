#include<cstdio>
#include<iostream>
using namespace std;
string S;
int id[1<<17];
main()
{
	cin>>S;
	char pre='a'-1;
	bool ng=false;
	for(int i=S.size();i--;)
	{
		if(i>0&&S[i-1]==S[i]&&pre+ng<=S[i])
		{
			id[i]=3;
			id[i-1]=2;
			i--;
		}
		else
		{
			id[i]=1;
			if(pre>S[i])ng=true;
			else if(pre<S[i])ng=false;
			pre=S[i];
		}
	}
	string ans="";
	for(int i=0;i<S.size();i++)if(id[i]==1)ans+=S[i];
	int st=0;
	for(int i=0;i<S.size();i++)
	{
		int cnt=ans.size()-st;
		if(id[i]==3)
		{
			cnt++;
			string ret="";
			ret+=S[i];
			if(cnt>10)
			{
				ret+=ans.substr(st,4)+"..."+ans.substr(ans.size()-2);
			}
			else
			{
				ret+=ans.substr(st);
			}
			printf("%d %s\n",cnt,ret.c_str());
		}
		else
		{
			string ret;
			if(cnt>10)
			{
				ret=ans.substr(st,5)+"..."+ans.substr(ans.size()-2);
			}
			else
			{
				ret=ans.substr(st);
			}
			printf("%d %s\n",cnt,ret.c_str());
		}
		if(id[i]==1)st++;
	}
}