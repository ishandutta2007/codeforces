#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	float s1,s2,ans1,ans2;
	scanf ("%f:%f",&s1,&s2);
	ans1=s1/12*360+s2/60*30;
	ans2=s2/60*360;
	if (ans1>=360)
	ans1-=360;
	cout << ans1 << " " << ans2;
}