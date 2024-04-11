#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n,ans=0;
	cin >> n;
	int m[n],r[n];
	for (int i=0;i<n;i++)
	cin >> m[i];
	for (int i=0;i<n;i++)
	cin >> r[i];
	for (int i=0;i<10000000;i++)
	{
		for (int x=0;x<n;x++)
		{
			if (i%m[x]==r[x])
			{
				ans++;
				break;
			}
		}
	}
	cout << setprecision(8) << fixed << (double)(1.0*ans/10000000);
}