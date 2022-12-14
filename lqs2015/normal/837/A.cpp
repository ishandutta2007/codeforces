#include<iostream>
#include<string>
using namespace std;
char c;
int ans,cur,n;
int main()
{
	cin>>n;
	getchar();
	for (int i=0;i<n;i++)
	{
		c=getchar();
		if (c>='A' && c<='Z') cur++;
		else if (c==' ')
		{
			ans=max(ans,cur);
			cur=0;
		}
	}
	ans=max(ans,cur);
	cout<<ans<<endl;
	return 0;
}