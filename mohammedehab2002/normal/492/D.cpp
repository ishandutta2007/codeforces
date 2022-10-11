#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector <int> vec;
	int n,i,ans;
	long long c1=0,c2=0,x,y;
	cin >> n >> x >> y;
	int arr[n];
	for (i=0;i<n;i++)
	cin >> arr[i];
	while (c1<x || c2<y)
	{
		if ((c1+1)*y>(c2+1)*x)
		{
			c2++;
			vec.push_back(2);
		}
		else if ((c1+1)*y<(c2+1)*x)
		{
			c1++;
			vec.push_back(1);
		}
		else
		{
			c1++;
			c2++;
			vec.push_back(3);
			vec.push_back(3);
		}
	}
	for (i=0;i<n;i++)
	{
		ans=vec[(arr[i]-1)%(x+y)];
		if (ans==1)
		cout << "Vanya\n";
		else if (ans==2)
		cout << "Vova\n";
		else
		cout << "Both\n";
	}
}