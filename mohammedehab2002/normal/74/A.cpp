#include <iostream>
#include <string.h>
using namespace std;
struct contestant{
	string name;
	int such;
	int unsuch;
	int a;
	int b;
	int c;
	int d;
	int e;
	int ap;
	int score;
};
int main()
{
	int n,i,maxi;
	string ans;
	cin >> n;
	contestant con[n];
	for (i=0;i<n;i++)
	{
		cin >> con[i].name >> con[i].such >> con[i].unsuch >> con[i].a >> con[i].b >> con[i].c >> con[i].d >> con[i].e;
		con[i].ap=con[i].a+con[i].b+con[i].c+con[i].d+con[i].e;
		con[i].score=con[i].ap+con[i].such*100+con[i].unsuch*-50;
	}
	maxi=con[0].score;
	ans=con[0].name;
	for (i=0;i<n;i++)
	{
		if (con[i].score>maxi)
		{
			maxi=con[i].score;
			ans=con[i].name;
		}
	}
	cout << ans;
}