#include <iostream>
#include <string>
using namespace std;

int main()
{
	string c,ans;
	bool f=0;
	cin>>c;
	int i;
	for(i=0;i<c.size()-2;i++)
	{
		if(c[i]=='a' && c[i+1]=='t' && i && !f)
		{
			f=1;
			ans+='@';
			i++;
		}
		else if(c[i]=='d' && c[i+1]=='o' && c[i+2]=='t' && i)
		{
			ans+='.';
			i+=2;
		}
		else
		{
			ans+=c[i];
		}
	}
	ans+=c.substr(i,c.size()-i);
	if(ans[ans.size()-1]=='.') ans=ans.substr(0,ans.size()-1)+"dot";
	cout<<ans<<endl;
	return 0;
}