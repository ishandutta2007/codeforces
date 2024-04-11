#include <iostream>

using namespace std;

int arr[5000];

int mask[5000];

int mask2[5000];

struct zapr
{
	int t;
	int l;
	int r;
	int o;
};


zapr arr2[5000];
int main()
{
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		arr[i]=1000000000;
	}
	for (int i=0;i<m;i++)
	{
		cin>>arr2[i].t>>arr2[i].l>>arr2[i].r>>arr2[i].o;
		int t,l,r,o;
		t=arr2[i].t;
		l=arr2[i].l;
		r=arr2[i].r;
		o=arr2[i].o;
		if (t==1)
		{
			for (int j=l-1;j<=r-1;j++)
			{
				mask[j]+=o;
			}
		}
		else
		{
			for (int j=l-1;j<=r-1;j++)
			{
				arr[j]=min(arr[j],o-mask[j]);
			}
		}
	}
	for (int i=0;i<m;i++)
	{
		int t,l,r,o;
		t=arr2[i].t;
		l=arr2[i].l;
		r=arr2[i].r;
		o=arr2[i].o;
		if (t==1)
		{
			for (int j=l-1;j<=r-1;j++)
			{
				mask2[j]+=o;
			}
		}
		else
		{
			int maxx=-1000000001;
			for (int j=l-1;j<=r-1;j++)
			{
				maxx=max(maxx,arr[j]+mask2[j]);
			}
			if (maxx!=o)
			{
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES\n";
	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}