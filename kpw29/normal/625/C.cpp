#include<bits/stdc++.h>
using namespace std;
int t[510][510],wynik, n, w ,p, e,x,y;
bool k[250010];
int main ()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> w;
	p=n*n;
	e=n-w;
	t[1][w]=p-e;
	wynik=t[1][w];
	k[t[1][w]]=1;
	for (int i=2; i<=n; i++)
	{
		t[i][w]=t[i-1][w]-e-1;
		wynik+=t[i][w];
		k[t[i][w]]=1;
	}
	cout << wynik << "\n";
	x=1;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<w; j++)
		{
			t[i][j]=x;
			x++;
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=n; j>=w+1; j--)
		{
			if (k[p]!=0)
			{
				while(k[p]!=0)
				{
					p--;
				}
			
			}
			t[i][j]=p;
			p--;
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++ )
		{
			cout << t[i][j] << " ";
		}
		cout << "\n";
	}
}