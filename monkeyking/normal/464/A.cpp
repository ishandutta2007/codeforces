#include <iostream>
#include <string>
using namespace std;
string s;

int main()
{
	int n,a,i,j,k;
	cin>>n>>a>>s;
	for(i=n-1;i>=0;i--)
	{
		for(int j=0;j<a;j++)
		{
			char c='a'+j;
			if(c>s[i])
			{
				if(i==0 || c!=s[i-1])
				{
					if(i<2 || c!=s[i-2])
					{
						string ans=s.substr(0,i)+c;
						int len=ans.length();
						while(len<n)
						{
							for(int k=0;k<a;k++)
							{
								char c='a'+k;
								if(len>=1 && c==ans[len-1]) continue;
								if(len>1 && c==ans[len-2]) continue;
								ans+=c;
								len++;
								break;
							}
						}
						cout<<ans<<endl;
						return 0;
					}
				}
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}