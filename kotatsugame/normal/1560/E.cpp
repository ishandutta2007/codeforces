#include<iostream>
#include<algorithm>
using namespace std;
int T;
string S;
bool ok[5<<17];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>S;
		string del="";
		int cnt[26]={};
		for(int i=S.size();i--;)
		{
			ok[i]=true;
			int c=S[i]-'a';
			if(!cnt[c]++)del+=S[i];
		}
		reverse(del.begin(),del.end());
		bool out=false;
		for(int i=0;i<del.size();i++)
		{
			int c=del[i]-'a';
			if(cnt[c]%(i+1)!=0)
			{
				out=true;
				break;
			}
			int x=cnt[c]/(i+1);
			for(int j=0;j<S.size();j++)
			{
				if(S[j]==del[i])x--;
				if(x!=0)ok[j]=false;
			}
		}
		int dl=-1;
		for(int i=0;i<S.size();i++)if(ok[i])
		{
			if(dl==-1)dl=i;
			else out=true;
		}
		if(out||dl==-1)cout<<-1<<endl;
		else
		{
			string ret=S.substr(0,dl+1);
			string s=ret,t="";
			for(int c:del)
			{
				t+=s;
				string ns="";
				for(char x:s)if(x!=c)ns+=x;
				s=ns;
			}
			if(t==S)cout<<ret<<" "<<del<<endl;
			else cout<<-1<<endl;
		}
	}
}