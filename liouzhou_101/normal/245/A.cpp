#include<cstdio>
#include<iostream>

using namespace std;

int n;
int px[4],py[4];

int main()
{
	cin>>n;
	while (n--)
	{
		int t,x,y;
		cin>>t>>x>>y;
		px[t]+=x;
		py[t]+=y;
	}
	for (int i=1;i<3;++i)
		puts((px[i]*2>=px[i]+py[i])?"LIVE":"DEAD");
	return 0;
}