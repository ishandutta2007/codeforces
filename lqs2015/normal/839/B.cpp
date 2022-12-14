#include<iostream>
using namespace std;
int n,k,totf,tott,toto;
int a[111];
int main()
{
	cin>>n>>k;
	for (int i=1;i<=k;i++) cin>>a[i];
	totf=n;tott=2*n;
	for (int i=1;i<=k;i++)
	{
		if (a[i]%4==3 && toto)
		{
			a[i]--;
			toto--;
		}
		if (a[i]%4==0)
		{
			if (a[i]/4<=totf) totf-=a[i]/4;
			else
			{
				tott-=(a[i]/4-totf)*2;
				totf=0;
			}
		}
		else if (a[i]%4==1)
		{
			if (a[i]/4<=totf) totf-=a[i]/4;
			else
			{
				tott-=(a[i]/4-totf)*2;
				totf=0;
			}
			if (toto>0) toto--;
			else if (totf>0)
			{
				totf--;
				tott++;
			}
			else tott--;
		}
		else if (a[i]%4==2)
		{
			if (a[i]/4<=totf) totf-=a[i]/4;
			else
			{
				tott-=(a[i]/4-totf)*2;
				totf=0;
			}
			if (tott<=0 && totf>0)
			{
				totf--;
				toto++;
			}
			else tott--;
		}
		else
		{
			if (a[i]/4+1<=totf) totf-=(a[i]/4+1);
			else
			{
				tott-=(a[i]/4+1-totf)*2;
				totf=0;
			}
		}
	}
	if (tott+toto/2<0) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}