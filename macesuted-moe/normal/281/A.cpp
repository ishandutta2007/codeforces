#include<bits/stdc++.h>
using namespace std;
int main()
{
	char c=getchar();
	if(c>'Z') cout<<(char)(c-'a'+'A');
	else      cout<<c;
	while(c!=EOF)
	{
		c=getchar();
		cout<<c;
	}
	cout<<endl;
	return 0;
}