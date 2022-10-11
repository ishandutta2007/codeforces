#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int main()
{
	int t,b,s,i,ans,ux,uy,f;
	cin >> t >> b >> s;
	double arr[t],time[t],test[t],mini;
	for (i=0;i<t;i++)
	cin >> arr[i];
	cin >> ux >> uy;
	if (s>b || t==2 || arr[1]>=ux)
	{
	cout << 2;
	exit(0);
	}
	else
	{
		for (i=1;i<t;i++)
		{
			test[i]=ux-arr[i];
			if (test[i]<0)
			test[i]*=-1;
		}
		for (i=1;i<t;i++)
		{
			time[i]=((sqrt(pow((ux-arr[i]),2)+pow(uy,2)))/s)+(arr[i]/b);
		}
		mini=time[1];
		ans=2;
		f=test[1];
		for (i=1;i<t;i++)
		{
			if (time[i]<mini)
			{
				mini=time[i];
				f=test[i];
				ans=i+1;
			}
			else if (mini==time[i])
			{
				if (test[i]<f)
				{
					ans=i+1;
					f=test[i];
					mini=time[i];
				}
			}
		}
		cout << ans;
	}
}