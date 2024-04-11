#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int stoit(string s)
{
	int ret;
	stringstream ss;
	ss<<s;
	ss>>ret;
	return ret;
}

int main()
{
	int n;
	string s,out[2];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		if(s[0]=='R'&&'0'<=s[1]&&'9'>=s[1]&&s.find("C")!=-1)
		{
			int a=1;
			while(s[a]>='0'&&s[a]<='9')a++;
			out[1]=s.substr(1,a-1);
			a++;
			out[0]=s.substr(a,s.length()-a);
			a=stoit(out[0]);
			out[0]="";
			while(a!=0)
			{
				if(a%26==0)
				{
					out[0]="Z"+out[0];
					if(a/26==1)a=0;
					else
					{
						a/=26;
						a--;
					}
				}
				else
				{
					out[0]=(char)(a%26+'A'-1)+out[0];
					a/=26;
				}
			}
			cout<<out[0]<<out[1]<<endl;
		}
		else
		{
			int a=0;
			while(s[a]<'0'||s[a]>'9')a++;
			out[0]=s.substr(a,s.length()-a);
			int outi=0,now;
			for(int j=0;j<=a-1;j++)
			{
				now=(s[j]-'A'+1);
				outi=26*outi+now;
			}
			cout<<"R"<<out[0]<<"C"<<outi<<endl;
		}
	}
	return 0;
}