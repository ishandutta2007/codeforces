#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	a=max(a,b);
	if(a==1) cout<<"1/1"<<endl;
	else if(a==2) cout<<"5/6"<<endl;
	else if(a==3) cout<<"2/3"<<endl;
	else if(a==4) cout<<"1/2"<<endl;
	else if(a==5) cout<<"1/3"<<endl;
	else if(a==6) cout<<"1/6"<<endl;
	return 0;
}