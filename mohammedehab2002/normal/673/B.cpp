#include <iostream>
using namespace std;
int main()
{
	int n,m,min1=100000000,max2=0;
	cin >> n >> m;
	if (!m)
	{
		cout << n-1;
		return 0;
	}
	for (int i=0;i<m;i++)
	{
		int e,f;
		cin >> e >> f;
		int a1=max(e,f),a2=min(e,f);
		min1=min(min1,a1);
		max2=max(max2,a2);
		if (max2>=min1)
		{
			cout << 0;
			return 0;
		}
	}
	cout << min1-max2;
}