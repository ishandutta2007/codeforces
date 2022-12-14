#include<bits/stdc++.h>
using namespace std;
string s;
int res;
int move1()
{
	printf("next 0 1\n");
	fflush(stdout);
	cin>>res;
	for (int i=1;i<=res;i++) cin>>s;
	return res;
}
int move2()
{
	printf("next 0\n");
	fflush(stdout);
	cin>>res;
	for (int i=1;i<=res;i++) cin>>s;
	return res;
}
int move3()
{
	printf("next 0 1 2 3 4 5 6 7 8 9\n");
	fflush(stdout);
	cin>>res;
	for (int i=1;i<=res;i++) cin>>s;
	return res;
}
int main()
{
	move1();
	move2();
	while(1)
	{
		move1();
		if (move2()==2) break;
	}
	while(1)
	{
		if (move3()==1) 
		{
			printf("done\n");
			fflush(stdout);
			return 0;
		}
	}
	printf("damn!It is wrong!");
	return 0;
}