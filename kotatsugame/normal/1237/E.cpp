#include<iostream>
using namespace std;
int N;
main()
{
	cin>>N;
	int a=1,b=2;
	bool flag=true;
	while(a<N&&b<N)
	{
		int t=a+b;
		if(flag)t++;
		flag=!flag;
		a=t;
		b=t+1;
	}
	if(a==N||b==N)cout<<1<<endl;
	else cout<<0<<endl;
}