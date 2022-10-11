#include <iostream>
using namespace std;
int main()
{
	int n,m,i,ans;
	cin >> n >> m;
	if (m>n)
	cout<< -1;
	else
	{
		ans=(n/2)+(n%2);
		for (i=1;i<=ans;i++)
		{
			if (i*m>=ans)
			{
				cout << i*m;
				break;
			}
		}
	}
}