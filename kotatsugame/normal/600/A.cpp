#include<iostream>
#include<string>
using namespace std;
string S,A,B;
main()
{
	cin>>S;
	string now;
	S+=',';
	for(char c:S)
	{
		if(c==','||c==';')
		{
			bool d=now.size()>0;
			for(char e:now)if(!isdigit(e))d=false;
			if(d&&(now.size()==1||now[0]!='0'))
			{
				A+=now+',';
			}
			else
			{
				B+=now+',';
			}
			now="";
		}
		else now+=c;
	}
	if(A.size()==0)A="-";
	else A='"'+A.substr(0,A.size()-1)+'"';
	if(B.size()==0)B="-";
	else B='"'+B.substr(0,B.size()-1)+'"';
	cout<<A<<endl<<B<<endl;
}