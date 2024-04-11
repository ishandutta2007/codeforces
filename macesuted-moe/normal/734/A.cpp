#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a=0,d=0;
	getchar();
	for(int i=0;i<n;i++)
	{
		char c=getchar();
		if(c=='A') a++;
		else       d++;
	}
	if(a==d) cout<<"Friendship"<<endl;
	if(a<d)  cout<<"Danik"<<endl;
	if(a>d)  cout<<"Anton"<<endl;
	return 0;
}