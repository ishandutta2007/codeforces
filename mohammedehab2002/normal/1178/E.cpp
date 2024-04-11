#include <iostream>
using namespace std;
int main()
{
	string s;
	cin >> s;
	string ans(s.size()/4*2+(s.size()%4!=0),'a');
	int a=0,b=s.size()-1,i=0,j=ans.size()-1;
	while (a+3<=b)
	{
		if (s[a]==s[b] || s[a]==s[b-1])
		{
			ans[i]=s[a];
			ans[j]=s[a];
		}
		if (s[a+1]==s[b] || s[a+1]==s[b-1])
		{
			ans[i]=s[a+1];
			ans[j]=s[a+1];
		}
		i++;
		j--;
		a+=2;
		b-=2;
	}
	if (a<=b)
	ans[ans.size()/2]=s[a];
	cout << ans;
}