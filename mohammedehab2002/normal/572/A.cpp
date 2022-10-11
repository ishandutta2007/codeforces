#include <iostream>
using namespace std;
int main()
{
	int n,y,k,m,i;
	cin >> n >> y >> k >> m;
	int a[n],b[y];
	for (i=0;i<n;i++)
	cin >> a[i];
	for (i=0;i<y;i++)
	cin >> b[i];
	if (a[k-1]<b[y-m])
	cout << "YES";
	else
	cout << "NO";
}