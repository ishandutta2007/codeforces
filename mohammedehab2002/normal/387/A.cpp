#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main()
{
	int ans1,ans2;
	string s,a;
	cin >> s >> a;
	ans1=atoi(s.substr(0,2).c_str())-atoi(a.substr(0,2).c_str());
	ans2=atoi(s.substr(3,5).c_str())-atoi(a.substr(3,5).c_str());
	if (ans2<0)
	{
		ans2+=60;
		ans1--;
	}
	if (ans1<0)
	ans1+=24;
	printf ("%02d:%02d",ans1,ans2);
}