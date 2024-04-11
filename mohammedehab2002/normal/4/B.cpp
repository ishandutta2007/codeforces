#include <iostream>
#include <stdlib.h>
using namespace std;
int d,th,i,j,ans=0,ans2=0,test,r,q,go,n1;
int main()
{
	cin >> d >> th;
	int mint[d],maxt[d];
	for (i=0;i<d;i++)
	{
		cin >> mint[i] >> maxt[i];
		ans+=maxt[i];
		ans2+=mint[i];
	}
	if (ans<th || ans2>th)
	{
	cout << "NO";
	exit(0);
	}
	else if (ans==th)
	{
		cout << "YES\n";
		for (j=0;j<d;j++)
		{
			cout << maxt[j] << " ";
		}
		exit(0);
	}
	else if (ans2==th)
	{
		cout << "YES\n";
		for (j=0;j<d;j++)
		{
			cout << mint[j] << " ";
		}
		exit(0);
	}
	r=th-ans2;
	if (ans>th && ans2<th)
	{
		cout << "YES\n";
		for (q=0;q<d;q++)
		{
				if (mint[q]+r<=maxt[q])
				{
				mint[q]+=r;
				break;
				}
				else
				go++;
		}
		if (go==d)
		{
			goto last;
		}
		for (j=0;j<d;j++)
		{
			cout << mint[j] << " ";
		}
		exit(0);
	}
	last: if (ans>th && ans2<th)
	{
			{
				while (r>0 && ans2<th)
				{
				for (q=0;q<d;q++)
				{
				n1=maxt[q]-mint[q];
				if (r>=n1)
				{
				mint[q]+=n1;
				ans2+=n1;
				r-=n1;
				}
				else
				{
					mint[q]+=r;
					ans2+=r;
					r-=r;
					goto out;
				}
				}
				}
				out: for (j=0;j<d;j++)
				{
					cout << mint[j] << " ";
				}
			}
	}
}