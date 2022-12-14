#include<iostream>
#include<cstdio>
using namespace std;
int n,q;
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		if (n%4==0) cout<<n/4<<endl;
		else if (n%4==1)
		{
			if (n<9) cout<<-1<<endl;
			else cout<<(n-9)/4+1<<endl;
		}
		else if (n%4==2)
		{
			if (n<6) cout<<-1<<endl;
			else cout<<(n-6)/4+1<<endl;
		}
		else
		{
			if (n<15) cout<<-1<<endl;
			else cout<<(n-15)/4+2<<endl;
		}
	}
	return 0;
}