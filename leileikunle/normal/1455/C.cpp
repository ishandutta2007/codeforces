#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T; cin>>T;
	while(T--)
	{
		int a,b;
		cin>>a>>b;
		if(a<b)
		{
			cout<<a-1<<" "<<b<<endl;
		}else if(a==b)
		{
			cout<<a-1<<" "<<a<<endl;
		}else{
			cout<<a-1<<" "<<b<<endl;
		}
	}
 }