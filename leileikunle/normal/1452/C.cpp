#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin>>t;
	while(t--)
	{
		string c;
		cin>>c;
		int a=0,b=0; 
		int sum = 0;
		for(int i=0;i<c.length();i++)
		{
			if(c[i] == '(') a++;
			else if(c[i] == '[') b++;
			else if(c[i] == ')'){
				if(a>0) a--, sum++;
			}else if(c[i] == ']'){
				if(b>0) b--, sum++;
			}
			
		}
		cout<<sum<<endl;
	}
}